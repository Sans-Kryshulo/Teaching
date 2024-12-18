using System;

namespace LibraryCatalog
{
    class Program
    {
        static void Main(string[] args)
        {
            var catalog = new LibraryCatalog();

            catalog.AddItem(new Book { Title = "1984", Author = "George Orwell", Genre = "Dystopian", Pages = 328 });
            catalog.AddItem(new Newspaper { Title = "The Times", Date = DateTime.Now, Headlines = new List<string> { "Headline 1", "Headline 2" } });
            catalog.AddItem(new Almanac { Title = "World Almanac", Works = new List<Book> { new Book { Title = "Moby Dick", Author = "Herman Melville" } } });

            Console.WriteLine("Каталог библиотеки:");
            foreach (var item in catalog.Items)
            {
                item.DisplayInfo();
            }

            Console.WriteLine("\nПоиск по названию '1984':");
            var itemByTitle = catalog.SearchByTitle("1984");
            itemByTitle?.DisplayInfo();

            Console.WriteLine("\nПоиск по автору 'George Orwell':");
            var itemsByAuthor = catalog.SearchByAuthor("George Orwell");
            foreach (var book in itemsByAuthor)
            {
                book.DisplayInfo();
            }

            catalog.SaveToFile("catalog.json");
            Console.WriteLine("\nКаталог сохранен в файл.");

            catalog = new LibraryCatalog();
            catalog.LoadFromFile("catalog.json");
            Console.WriteLine("\nКаталог загружен из файла:");

            foreach (var item in catalog.Items)
            {
                item.DisplayInfo();
            }
        }
    }
}