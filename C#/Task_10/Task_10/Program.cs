using System;
using System.Collections.Generic;

namespace FirmApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var firms = new List<Firm>
            {
                new Firm
                {
                    Name = "TechFood",
                    FoundedDate = new DateTime(2020, 5, 15),
                    BusinessProfile = "IT",
                    Director = "John White",
                    EmployeeCount = 150,
                    Address = "London"
                },
                new Firm
                {
                    Name = "MarketingPro",
                    FoundedDate = new DateTime(2018, 10, 20),
                    BusinessProfile = "Marketing",
                    Director = "Emily Brown",
                    EmployeeCount = 80,
                    Address = "New York"
                },
                new Firm
                {
                    Name = "FoodWorld",
                    FoundedDate = new DateTime(2019, 3, 12),
                    BusinessProfile = "Marketing",
                    Director = "Robert Black",
                    EmployeeCount = 300,
                    Address = "London"
                },
                new Firm
                {
                    Name = "DesignStudio",
                    FoundedDate = new DateTime(2021, 6, 1),
                    BusinessProfile = "Design",
                    Director = "Anna White",
                    EmployeeCount = 50,
                    Address = "Berlin"
                }
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
                            Queries.ExecuteQueries(firms);
                            ////////////////////////////
                            continueBank = true;
                            break;
                        case "2":
                            Queries.ExecuteMethodSyntaxQueries(firms);
                            ////////////////////
                            continueBank = true;
                            break;
                        case "3":
                            EmployeeQueries.ExecuteEmployeeQueries(firms);
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
