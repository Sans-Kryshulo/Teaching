namespace LibraryCatalog
{
    public class Newspaper : IItem
    {
        public string Title { get; set; }
        public DateTime Date { get; set; }
        public List<string> Headlines { get; set; }

        public void DisplayInfo()
        {
            Console.WriteLine($"Газета: {Title}, Дата: {Date:d}, Заголовки: {string.Join(", ", Headlines)}");
        }
    }
}
