namespace LibraryCatalog
{
    public class Book : IItem
    {
        public string Title { get; set; }
        public string Author { get; set; }
        public string Genre { get; set; }
        public int Pages { get; set; }

        public void DisplayInfo()
        {
            Console.WriteLine($"Книга: {Title}, Автор: {Author}, Жанр: {Genre}, Страниц: {Pages}");
        }
    }
}
