namespace LibraryCatalog
{
    public interface IItem
    {
        string Title { get; }
        void DisplayInfo();
    }
}