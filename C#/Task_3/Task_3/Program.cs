using System;
using SquareApp;
using PalindromeApp;
using ArrayFilterApp;
using WebsiteApp;
using MagazineApp;
using StoreApp;

namespace TaskApp
{
    class Program
    {
        static void Main(string[] args)
        {
            bool continueProgram = true;
            while (continueProgram)
            {
                Console.WriteLine("Введите номер задания:");
                Console.WriteLine("1: SquareApp");
                Console.WriteLine("2: PalindromeApp");
                Console.WriteLine("3: ArrayFilterApp");
                Console.WriteLine("4: WebsiteApp");
                Console.WriteLine("5: MagazineApp");
                Console.WriteLine("6: StoreApp");
                string taskChoice = Console.ReadLine();
                switch (taskChoice)
                {
                    case "1":
                        Console.WriteLine("Введите длину стороны квадрата:");
                        if (!int.TryParse(Console.ReadLine(), out int sideLength))
                        {
                            Console.WriteLine("Ошибка: Введите корректное число.");
                            return;
                        }

                        Console.WriteLine("Введите символ для квадрата:");
                        char symbol = Console.ReadKey().KeyChar;
                        Console.WriteLine();

                        try
                        {
                            SquareDrawer.DrawSquare(sideLength, symbol);
                        }
                        catch (ArgumentException ex)
                        {
                            Console.WriteLine($"Ошибка: {ex.Message}");
                        }
                        break;
                    case "2":
                        Console.WriteLine("Введите число:");
                        if (!int.TryParse(Console.ReadLine(), out int number))
                        {
                            Console.WriteLine("Ошибка: Введите корректное число.");
                            return;
                        }

                        bool isPalindrome = PalindromeChecker.IsPalindrome(number);
                        if (isPalindrome)
                        {
                            Console.WriteLine($"Число {number} является палиндромом.");
                        }
                        else
                        {
                            Console.WriteLine($"Число {number} не является палиндромом.");
                        }
                        break;
                    case "3":
                        Console.WriteLine("Введите элементы оригинального массива через пробел:");
                        int[] originalArray = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);

                        Console.WriteLine("Введите элементы массива для фильтрации через пробел:");
                        int[] filterArray = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);

                        int[] filteredArray = ArrayFilter.FilterArray(originalArray, filterArray);

                        Console.WriteLine("Результат фильтрации:");
                        Console.WriteLine(string.Join(" ", filteredArray));
                        break;
                    case "4":
                        Website website = new Website();
                        website.InputData();
                        Console.WriteLine();
                        website.DisplayData();
                        break;
                    case "5":
                        Magazine magazine = new Magazine();
                        magazine.InputData();
                        Console.WriteLine();
                        magazine.DisplayData();
                        break;
                    case "6":
                        Store store = new Store();
                        store.InputData();
                        Console.WriteLine();
                        store.DisplayData();
                        break;
                        break;
                    default:
                        Console.WriteLine("Ошибка: неверный номер задания.");
                        break;
                }

                continueProgram = AskToContinue();
            }
            static bool AskToContinue()
            {
                Console.WriteLine("Хотите продолжить работу программы? (Y/N)");
                string response = Console.ReadLine().Trim().ToUpper();

                while (response != "Y" && response != "N")
                {
                    Console.WriteLine("Ошибка: введите Y для продолжения или N для завершения.");
                    response = Console.ReadLine().Trim().ToUpper();
                }

                return response == "Y";
            }
        }
    }
}