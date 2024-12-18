using System;
using System.Collections.Generic;
using System.Linq;

namespace PhoneApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var phones = new List<Phone>
            {
                new Phone { Name = "iPhone 13", Manufacturer = "Apple", Price = 799, ReleaseDate = new DateTime(2021, 9, 24) },
                new Phone { Name = "Galaxy S22", Manufacturer = "Samsung", Price = 999, ReleaseDate = new DateTime(2022, 2, 9) },
                new Phone { Name = "Pixel 6", Manufacturer = "Google", Price = 599, ReleaseDate = new DateTime(2021, 10, 28) },
                new Phone { Name = "Xperia 1 IV", Manufacturer = "Sony", Price = 1299, ReleaseDate = new DateTime(2022, 5, 11) },
                new Phone { Name = "Nokia G50", Manufacturer = "Nokia", Price = 199, ReleaseDate = new DateTime(2021, 9, 22) }
            };

            bool continueProgram = true;
            while (continueProgram)
            {
                bool continueBank = true;
                Console.WriteLine("Введите номер задания от 1 до 3 (0 - выход): ");

                while (continueBank == true)
                {

                    Console.WriteLine("Укажите номер:");

                    string numberTask = Console.ReadLine();

                    switch (numberTask)
                    {
                        case "0":
                            continueBank = false;
                            break;
                        case "1":
                            Console.WriteLine($"Количество телефонов: {phones.Count}");

                            Console.WriteLine($"Количество телефонов с ценой больше 100: {phones.Count(p => p.Price > 100)}");

                            Console.WriteLine($"Количество телефонов с ценой от 400 до 700: {phones.Count(p => p.Price >= 400 && p.Price <= 700)}");

                            string manufacturer = "Apple";
                            Console.WriteLine($"Количество телефонов производителя {manufacturer}: {phones.Count(p => p.Manufacturer == manufacturer)}");

                            var minPricePhone = phones.OrderBy(p => p.Price).First();
                            Console.WriteLine($"Телефон с минимальной ценой: {minPricePhone}");

                            var maxPricePhone = phones.OrderByDescending(p => p.Price).First();
                            Console.WriteLine($"Телефон с максимальной ценой: {maxPricePhone}");

                            var oldestPhone = phones.OrderBy(p => p.ReleaseDate).First();
                            Console.WriteLine($"Самый старый телефон: {oldestPhone}");

                            var newestPhone = phones.OrderByDescending(p => p.ReleaseDate).First();
                            Console.WriteLine($"Самый свежий телефон: {newestPhone}");

                            var averagePrice = phones.Average(p => p.Price);
                            Console.WriteLine($"Средняя цена телефона: {averagePrice:C}");
                            ////////////////////////////
                            continueBank = true;
                            break;
                        case "2":

                            var topExpensivePhones = phones.OrderByDescending(p => p.Price).Take(5);
                            Console.WriteLine("Пять самых дорогих телефонов:");
                            foreach (var phone in topExpensivePhones)
                            {
                                Console.WriteLine(phone);
                            }

                            var topCheapPhones = phones.OrderBy(p => p.Price).Take(5);
                            Console.WriteLine("\nПять самых дешевых телефонов:");
                            foreach (var phone in topCheapPhones)
                            {
                                Console.WriteLine(phone);
                            }

                            var topOldestPhones = phones.OrderBy(p => p.ReleaseDate).Take(3);
                            Console.WriteLine("\nТри самых старых телефона:");
                            foreach (var phone in topOldestPhones)
                            {
                                Console.WriteLine(phone);
                            }

                            var topNewestPhones = phones.OrderByDescending(p => p.ReleaseDate).Take(3);
                            Console.WriteLine("\nТри самых новых телефона:");
                            foreach (var phone in topNewestPhones)
                            {
                                Console.WriteLine(phone);
                            }
                            ////////////////////
                            continueBank = true;
                            break;
                        case "3":
                            var manufacturerStats = phones.GroupBy(p => p.Manufacturer)
                                                          .Select(group => new { Manufacturer = group.Key, Count = group.Count() });
                            Console.WriteLine("\nСтатистика по количеству телефонов каждого производителя:");
                            foreach (var stat in manufacturerStats)
                            {
                                Console.WriteLine($"{stat.Manufacturer}: {stat.Count}");
                            }

                            var modelStats = phones.GroupBy(p => p.Name)
                                                   .Select(group => new { Model = group.Key, Count = group.Count() });
                            Console.WriteLine("\nСтатистика по количеству моделей телефонов:");
                            foreach (var stat in modelStats)
                            {
                                Console.WriteLine($"{stat.Model}: {stat.Count}");
                            }

                            var yearStats = phones.GroupBy(p => p.ReleaseDate.Year)
                                                  .Select(group => new { Year = group.Key, Count = group.Count() });
                            Console.WriteLine("\nСтатистика телефонов по годам:");
                            foreach (var stat in yearStats)
                            {
                                Console.WriteLine($"{stat.Year}: {stat.Count}");
                            }
                            ////////////////////
                            continueBank = true;
                            break;
                        default:
                            Console.WriteLine("Ошибка: неверный номер запроса.");
                            continueBank = true;
                            break;
                    }

                }
                continueProgram = AskToContinue();
            }

            static bool AskToContinue()
            {
                Console.WriteLine("Выйти из программы? (Y/N)");
                string response = Console.ReadLine().Trim().ToUpper();

                while (response != "Y" && response != "N")
                {
                    Console.WriteLine("Ошибка: введите Y для продолжения или N для завершения.");
                    response = Console.ReadLine().Trim().ToUpper();
                }

                return response == "N";
            }
        }
    }
}
