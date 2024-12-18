using System;

class Program
{
    static void Main(string[] args)
    {
        Adaptee adaptee = new Adaptee();

        ITarget target = new Adapter(adaptee);

        Console.WriteLine("Клиент вызывает Request через адаптер:");
        target.Request();
    }
}
