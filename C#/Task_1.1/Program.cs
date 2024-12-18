using System;
using System.Globalization;

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
                Console.WriteLine("1: FizzBuzz");
                Console.WriteLine("2: Процент от числа");
                Console.WriteLine("3: Создание числа из четырёх цифр");
                Console.WriteLine("4: Обмен цифр в шестизначном числе");
                Console.WriteLine("5: Определение сезона и дня недели по дате");
                Console.WriteLine("6: Перевод температуры");
                Console.WriteLine("7: Четные числа в диапазоне");

                string taskChoice = Console.ReadLine();
                switch (taskChoice)
                {
                    case "1":
                        FizzBuzzTask();
                        break;
                    case "2":
                        PercentageTask();
                        break;
                    case "3":
                        CreateNumberFromDigitsTask();
                        break;
                    case "4":
                        SwapDigitsInNumberTask();
                        break;
                    case "5":
                        DetermineSeasonAndDayOfWeekTask();
                        break;
                    case "6":
                        TemperatureConversionTask();
                        break;
                    case "7":
                        EvenNumbersInRangeTask();
                        break;
                    default:
                        Console.WriteLine("Ошибка: неверный номер задания.");
                        break;
                }

                continueProgram = AskToContinue();
            }
        }

        static void FizzBuzzTask()
        {
            Console.WriteLine("Введите число от 1 до 100:");

            string input = Console.ReadLine();
            int number;

            if (int.TryParse(input, out number))
            {
                if (number >= 1 && number <= 100)
                {
                    if (number % 3 == 0 && number % 5 == 0)
                    {
                        Console.WriteLine("Fizz Buzz");
                    }
                    else if (number % 3 == 0)
                    {
                        Console.WriteLine("Fizz");
                    }
                    else if (number % 5 == 0)
                    {
                        Console.WriteLine("Buzz");
                    }
                    else
                    {
                        Console.WriteLine(number);
                    }
                }
                else
                {
                    Console.WriteLine("Ошибка: введенное число не находится в диапазоне от 1 до 100.");
                }
            }
            else
            {
                Console.WriteLine("Ошибка: введено не число.");
            }
        }

        static void PercentageTask()
        {
            Console.WriteLine("Введите число:");

            string valueInput = Console.ReadLine();
            double value;

            Console.WriteLine("Введите процент:");

            string percentageInput = Console.ReadLine();
            double percentage;

            if (double.TryParse(valueInput, out value) && double.TryParse(percentageInput, out percentage))
            {
                double result = CalculatePercentage(value, percentage);
                Console.WriteLine($"{percentage}% от {value} равно {result}");
            }
            else
            {
                Console.WriteLine("Ошибка: одно или оба введенных значения не являются числами.");
            }
        }

        static double CalculatePercentage(double value, double percentage)
        {
            return (value * percentage) / 100;
        }

        static void CreateNumberFromDigitsTask()
        {
            Console.WriteLine("Введите четыре цифры:");

            char[] digits = new char[4];
            for (int i = 0; i < 4; i++)
            {
                Console.WriteLine($"Введите цифру {i + 1}:");
                string input = Console.ReadLine();
                
                if (input.Length == 1 && char.IsDigit(input[0]))
                {
                    digits[i] = input[0];
                }
                else
                {
                    Console.WriteLine("Ошибка: необходимо ввести одну цифру.");
                    i--; // Повторяем текущий шаг
                }
            }

            string number = new string(digits);
            Console.WriteLine($"Сформированное число: {number}");
        }

        static void SwapDigitsInNumberTask()
        {
            Console.WriteLine("Введите шестизначное число:");

            string input = Console.ReadLine();

            if (input.Length == 6 && int.TryParse(input, out _))
            {
                Console.WriteLine("Введите номер первого разряда для обмена (1-6):");
                int firstIndex = GetDigitIndex();

                Console.WriteLine("Введите номер второго разряда для обмена (1-6):");
                int secondIndex = GetDigitIndex();

                char[] digits = input.ToCharArray();
                char temp = digits[firstIndex - 1];
                digits[firstIndex - 1] = digits[secondIndex - 1];
                digits[secondIndex - 1] = temp;

                string result = new string(digits);
                Console.WriteLine($"Результат: {result}");
            }
            else
            {
                Console.WriteLine("Ошибка: введено не шестизначное число.");
            }
        }

        static int GetDigitIndex()
        {
            while (true)
            {
                string input = Console.ReadLine();
                if (int.TryParse(input, out int index) && index >= 1 && index <= 6)
                {
                    return index;
                }
                else
                {
                    Console.WriteLine("Ошибка: необходимо ввести число от 1 до 6.");
                }
            }
        }

        static void DetermineSeasonAndDayOfWeekTask()
        {
            Console.WriteLine("Введите дату в формате ДД.ММ.ГГГГ:");

            string input = Console.ReadLine();
            if (DateTime.TryParseExact(input, "dd.MM.yyyy", CultureInfo.InvariantCulture, DateTimeStyles.None, out DateTime date))
            {
                string season = GetSeason(date);
                string dayOfWeek = date.DayOfWeek.ToString();
                Console.WriteLine($"{season} {dayOfWeek}");
            }
            else
            {
                Console.WriteLine("Ошибка: неверный формат даты.");
            }
        }

        static string GetSeason(DateTime date)
        {
            int month = date.Month;
            int day = date.Day;

            if ((month == 12 && day >= 21) || month == 1 || month == 2 || (month == 3 && day < 21))
            {
                return "Winter";
            }
            else if ((month == 3 && day >= 21) || month == 4 || month == 5 || (month == 6 && day < 21))
            {
                return "Spring";
            }
            else if ((month == 6 && day >= 21) || month == 7 || month == 8 || (month == 9 && day < 23))
            {
                return "Summer";
            }
            else
            {
                return "Fall";
            }
        }
        static void TemperatureConversionTask()
        {
            Console.WriteLine("Введите температуру:");
            string input = Console.ReadLine();
            double temperature;

            if (double.TryParse(input, out temperature))
            {
                Console.WriteLine("Выберите конвертацию:");
                Console.WriteLine("1: Из Фаренгейта в Цельсий");
                Console.WriteLine("2: Из Цельсия в Фаренгейт");

                string choice = Console.ReadLine();
                switch (choice)
                {
                    case "1":
                        double celsius = FahrenheitToCelsius(temperature);
                        Console.WriteLine($"{temperature}°F равно {celsius:F2}°C");
                        break;
                    case "2":
                        double fahrenheit = CelsiusToFahrenheit(temperature);
                        Console.WriteLine($"{temperature}°C равно {fahrenheit:F2}°F");
                        break;
                    default:
                        Console.WriteLine("Ошибка: неверный выбор конвертации.");
                        break;
                }
            }
            else
            {
                Console.WriteLine("Ошибка: введено не число.");
            }
        }

        static double FahrenheitToCelsius(double fahrenheit)
        {
            return (fahrenheit - 32) * 5 / 9;
        }

        static double CelsiusToFahrenheit(double celsius)
        {
            return (celsius * 9 / 5) + 32;
        }

        static void EvenNumbersInRangeTask()
        {
            Console.WriteLine("Введите первое число диапазона:");
            string input1 = Console.ReadLine();
            Console.WriteLine("Введите второе число диапазона:");
            string input2 = Console.ReadLine();

            if (int.TryParse(input1, out int number1) && int.TryParse(input2, out int number2))
            {
                if (number1 > number2)
                {
                    int temp = number1;
                    number1 = number2;
                    number2 = temp;
                }

                Console.WriteLine($"Четные числа в диапазоне от {number1} до {number2}:");
                for (int i = number1; i <= number2; i++)
                {
                    if (i % 2 == 0)
                    {
                        Console.WriteLine(i);
                    }
                }
            }
            else
            {
                Console.WriteLine("Ошибка: одно или оба введенных значения не являются числами.");
            }
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
