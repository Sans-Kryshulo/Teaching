public class Adapter : ITarget
{
    private readonly Adaptee _adaptee;

    public Adapter(Adaptee adaptee)
    {
        _adaptee = adaptee;
    }

    public void Request()
    {
        Console.WriteLine("Адаптация вызова...");
        _adaptee.SpecificRequest();
    }
}
