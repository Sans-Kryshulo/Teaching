using CafeQueueApp;
using EmployeeManagementApp;
using EnglishFrenchDictionaryApp;
using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
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
                        EmployeeManager manager1 = new EmployeeManager();

                        // Добавление сотрудников
                        manager1.AddEmployee("jdoe", "password123");
                        manager1.AddEmployee("asmith", "pass456");
                        manager1.AddEmployee("bjones", "mypassword");

                        // Получение пароля сотрудника
                        string password = manager1.GetPassword("jdoe");
                        if (password != null)
                        {
                            Console.WriteLine($"Пароль сотрудника 'jdoe': {password}");
                        }

                        // Изменение информации о сотруднике
                        manager1.UpdateEmployee("asmith", "asmith_new", "newpassword");

                        // Удаление сотрудника
                        manager1.RemoveEmployee("bjones");

                        // Попытка получения пароля удаленного сотрудника
                        manager1.GetPassword("bjones");

                        // Получение пароля обновленного сотрудника
                        string newPassword = manager1.GetPassword("asmith_new");
                        if (newPassword != null)
                        {
                            Console.WriteLine($"Пароль сотрудника 'asmith_new': {newPassword}");
                        }
                        ////////////////////
                        continueBank = true;
                        break;
                    case "2":
                        var manager2 = new DictionaryManager();

                        // Добавление слов и их переводов
                        manager2.AddWord("hello", new List<string> { "bonjour", "salut" });
                        manager2.AddWord("goodbye", new List<string> { "au revoir", "adieu" });

                        // Поиск перевода
                        var translations = manager2.GetTranslations("hello");
                        if (translations != null)
                        {
                            Console.WriteLine("Переводы слова 'hello': " + string.Join(", ", translations));
                        }

                        // Изменение слова
                        manager2.UpdateWord("goodbye", "farewell");

                        // Изменение перевода
                        manager2.UpdateTranslation("hello", "salut", "coucou");

                        // Удаление перевода
                        manager2.RemoveTranslation("hello", "bonjour");

                        // Удаление слова
                        manager2.RemoveWord("farewell");

                        // Попытка получить переводы удаленного слова
                        manager2.GetTranslations("farewell");

                        ////////////////////
                        continueBank = true;
                        break;
                    case "3":
                        var cafeManager = new CafeQueueManager();

                        // Добавление клиентов
                        cafeManager.EnqueueCustomer(new Customer("Alice", false));
                        cafeManager.EnqueueCustomer(new Customer("Bob", false));
                        cafeManager.EnqueueCustomer(new Customer("Charlie", true, "12:00"));
                        cafeManager.EnqueueCustomer(new Customer("David", false));
                        cafeManager.EnqueueCustomer(new Customer("Eve", true, "12:30"));

                        // Показ текущей очереди и резервов
                        cafeManager.DisplayQueue();
                        cafeManager.DisplayReservations();

                        // Освобождение столиков
                        cafeManager.ServeNextCustomer();
                        cafeManager.ServeNextCustomer();
                        cafeManager.ServeNextCustomer();
                        cafeManager.ServeNextCustomer();
                        cafeManager.ServeNextCustomer();

                        // Попытка обслужить следующего клиента, когда никого нет
                        cafeManager.ServeNextCustomer();

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
