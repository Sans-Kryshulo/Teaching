using System;

namespace TamagotchiApp
{
    class Program
    {
        static Tamagotchi tamagotchi;

        static void Main(string[] args)
        {
            tamagotchi = new Tamagotchi();

            tamagotchi.OnRequest += HandleRequest;
            tamagotchi.OnStatusChange += DisplayStatus;
            tamagotchi.OnDeath += HandleDeath;

            tamagotchi.StartLifeCycle();
        }

        static void HandleRequest(string request)
        {
            Console.Clear();
            Console.WriteLine($"Тамагочи просит: {request}");
            Console.WriteLine("Введите ваш ответ:");

            string userInput = Console.ReadLine();
            tamagotchi.FulfillRequest(userInput);
        }

        static void DisplayStatus(string status)
        {
            Console.Clear();
            Console.WriteLine(status);
            Thread.Sleep(2000); 
        }

        static void HandleDeath()
        {
            Console.Clear();
            Console.WriteLine("Тамагочи умер. Игра окончена.");
        }
    }
}

