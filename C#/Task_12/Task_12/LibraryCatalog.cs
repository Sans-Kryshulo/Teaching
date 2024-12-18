using System.Text.Json;
using System.Text.Json.Serialization;

namespace LibraryCatalog
{
    public class LibraryCatalog
    {
        public List<IItem> Items { get; private set; } = new List<IItem>();

        public void AddItem(IItem item)
        {
            Items.Add(item);
        }

        public IItem SearchByTitle(string title)
        {
            return Items.FirstOrDefault(item => item.Title.Equals(title, StringComparison.OrdinalIgnoreCase));
        }

        public List<Book> SearchByAuthor(string author)
        {
            return Items.OfType<Book>().Where(book => book.Author.Equals(author, StringComparison.OrdinalIgnoreCase)).ToList();
        }

        public void SaveToFile(string fileName)
        {
            var options = new JsonSerializerOptions
            {
                WriteIndented = true,
                Converters = { new PolymorphicJsonConverter<IItem>() }
            };
            var json = JsonSerializer.Serialize(Items, options);
            File.WriteAllText(fileName, json);
        }

        public void LoadFromFile(string fileName)
        {
            if (File.Exists(fileName))
            {
                var options = new JsonSerializerOptions
                {
                    Converters = { new PolymorphicJsonConverter<IItem>() }
                };
                var json = File.ReadAllText(fileName);
                Items = JsonSerializer.Deserialize<List<IItem>>(json, options) ?? new List<IItem>();
            }
        }
    }

    public class PolymorphicJsonConverter<T> : JsonConverter<T>
    {
        public override bool CanConvert(Type typeToConvert)
        {
            return typeof(T).IsAssignableFrom(typeToConvert);
        }

        public override T? Read(ref Utf8JsonReader reader, Type typeToConvert, JsonSerializerOptions options)
        {
            if (reader.TokenType != JsonTokenType.StartObject)
                throw new JsonException();

            using (var document = JsonDocument.ParseValue(ref reader))
            {
                var rootElement = document.RootElement;
                if (!rootElement.TryGetProperty("Type", out JsonElement typeProperty))
                    throw new JsonException("Свойство 'Type' не найдено.");

                var typeName = typeProperty.GetString();
                if (typeName == null)
                    throw new JsonException("Свойство 'Type' имеет значение null.");

                Type actualType = Type.GetType(typeName) ?? throw new JsonException($"Неизвестный тип: {typeName}");

                var optionsWithoutConverter = new JsonSerializerOptions(options);
                optionsWithoutConverter.Converters.Remove(this);

                var jsonObject = new Dictionary<string, JsonElement>();
                foreach (var property in rootElement.EnumerateObject())
                {
                    if (property.Name != "Type")
                    {
                        jsonObject.Add(property.Name, property.Value);
                    }
                }
                var json = JsonSerializer.Serialize(jsonObject);

                return (T?)JsonSerializer.Deserialize(json, actualType, optionsWithoutConverter);
            }
        }

        public override void Write(Utf8JsonWriter writer, T value, JsonSerializerOptions options)
        {
            var type = value.GetType();

            var optionsWithoutConverter = new JsonSerializerOptions(options);
            optionsWithoutConverter.Converters.Remove(this);

            var json = JsonSerializer.Serialize(value, type, optionsWithoutConverter);
            using (var document = JsonDocument.Parse(json))
            {
                writer.WriteStartObject();

                writer.WriteString("Type", type.AssemblyQualifiedName);

                foreach (var property in document.RootElement.EnumerateObject())
                {
                    property.WriteTo(writer);
                }

                writer.WriteEndObject();
            }
        }
    }
}
