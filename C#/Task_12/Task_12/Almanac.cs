namespace LibraryCatalog
{
    public class Almanac : IItem
    {
        public string Title { get; set; }
        public List<Book> Works { get; set; }

        public void DisplayInfo()
        {
            Console.WriteLine($"Альманах: {Title}, Произведения:");
            foreach (var book in Works)
            {
                Console.WriteLine($"  - {book.Title} (Автор: {book.Author})");
            }
        }
    }
}
