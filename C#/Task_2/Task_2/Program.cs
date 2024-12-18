using System;
using System.Data;

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
                Console.WriteLine("1: Анализ массивов: одномерный и двумерный");
                Console.WriteLine("2: Сумма элементов между минимумом и максимумом");
                Console.WriteLine("3: Шифрование и расшифрование с помощью шифра Цезаря");
                Console.WriteLine("4: Операции над матрицами");
                Console.WriteLine("5: Калькулятор арифметических выражений");
                Console.WriteLine("6: Изменение регистра первой буквы предложений");
                Console.WriteLine("7: Проверка текста на недопустимые слова и замена их на ***");

                string taskChoice = Console.ReadLine();
                switch (taskChoice)
                {
                    case "1":
                        Task_1();
                        break;
                    case "2":
                        Task_2();
                        break;
                    case "3":
                        Task_3();
                        break;
                    case "4":
                        Task_4();
                        break;
                    case "5":
                        Task_5();
                        break;
                    case "6":
                        Task_6();
                        break;
                    case "7":
                        Task_7();
                        break;
                    default:
                        Console.WriteLine("Ошибка: неверный номер задания.");
                        break;
                }

                continueProgram = AskToContinue();
            }

            static void Task_1()
            {
                int[] A = new int[5];
                double[,] B = new double[3, 4];

                Console.WriteLine("Введите 5 элементов массива A:");
                for (int i = 0; i < A.Length; i++)
                {
                    Console.Write($"A[{i + 1}] = ");
                    A[i] = int.Parse(Console.ReadLine());
                }

                Random rand = new Random();
                for (int i = 0; i < B.GetLength(0); i++)
                {
                    for (int j = 0; j < B.GetLength(1); j++)
                    {
                        B[i, j] = rand.NextDouble() * 100;
                    }
                }

                Console.WriteLine("\nМассив A:");
                foreach (int num in A)
                {
                    Console.Write(num + " ");
                }
                Console.WriteLine();

                Console.WriteLine("\nМассив B:");
                for (int i = 0; i < B.GetLength(0); i++)
                {
                    for (int j = 0; j < B.GetLength(1); j++)
                    {
                        Console.Write($"{B[i, j]:F2}\t");
                    }
                    Console.WriteLine();
                }

                double maxElement = A[0];
                double minElement = A[0];
                foreach (int num in A)
                {
                    if (num > maxElement)
                        maxElement = num;
                    if (num < minElement)
                        minElement = num;
                }

                foreach (double num in B)
                {
                    if (num > maxElement)
                        maxElement = num;
                    if (num < minElement)
                        minElement = num;
                }

                double sumAll = 0;
                foreach (int num in A)
                {
                    sumAll += num;
                }

                foreach (double num in B)
                {
                    sumAll += num;
                }

                double productAll = 1;
                foreach (int num in A)
                {
                    productAll *= num;
                }

                foreach (double num in B)
                {
                    productAll *= num;
                }

                int sumEvenA = 0;
                foreach (int num in A)
                {
                    if (num % 2 == 0)
                        sumEvenA += num;
                }

                double sumOddColsB = 0;
                for (int j = 1; j < B.GetLength(1); j += 2)
                {
                    for (int i = 0; i < B.GetLength(0); i++)
                    {
                        sumOddColsB += B[i, j];
                    }
                }

                Console.WriteLine($"\nОбщий максимальный элемент: {maxElement}");
                Console.WriteLine($"Общий минимальный элемент: {minElement}");
                Console.WriteLine($"Общая сумма всех элементов: {sumAll}");
                Console.WriteLine($"Общее произведение всех элементов: {productAll}");
                Console.WriteLine($"Сумма четных элементов массива A: {sumEvenA}");
                Console.WriteLine($"Сумма нечетных столбцов массива B: {sumOddColsB:F2}");
            }

            static void Task_2()
            {
                int[,] array = new int[5, 5];
                Random rand = new Random();

                for (int i = 0; i < array.GetLength(0); i++)
                {
                    for (int j = 0; j < array.GetLength(1); j++)
                    {
                        array[i, j] = rand.Next(-100, 101);
                    }
                }

                Console.WriteLine("Массив:");
                for (int i = 0; i < array.GetLength(0); i++)
                {
                    for (int j = 0; j < array.GetLength(1); j++)
                    {
                        Console.Write($"{array[i, j]}\t");
                    }
                    Console.WriteLine();
                }

                int minElement = array[0, 0];
                int maxElement = array[0, 0];
                (int, int) minIndex = (0, 0);
                (int, int) maxIndex = (0, 0);

                for (int i = 0; i < array.GetLength(0); i++)
                {
                    for (int j = 0; j < array.GetLength(1); j++)
                    {
                        if (array[i, j] < minElement)
                        {
                            minElement = array[i, j];
                            minIndex = (i, j);
                        }
                        if (array[i, j] > maxElement)
                        {
                            maxElement = array[i, j];
                            maxIndex = (i, j);
                        }
                    }
                }

                int sumBetween = 0;
                bool adding = false;
                foreach (var index in GetAllIndices(array.GetLength(0), array.GetLength(1)))
                {
                    if (index == minIndex || index == maxIndex)
                    {
                        if (!adding)
                        {
                            adding = true;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else if (adding)
                    {
                        sumBetween += array[index.Item1, index.Item2];
                    }
                }

                Console.WriteLine($"\nМинимальный элемент: {minElement} (индекс {minIndex})");
                Console.WriteLine($"Максимальный элемент: {maxElement} (индекс {maxIndex})");
                Console.WriteLine($"Сумма элементов между минимальным и максимальным элементами: {sumBetween}");
            }

            static void Task_3()
            {
                Console.WriteLine("Введите строку для шифрования:");
                string input = Console.ReadLine();

                Console.WriteLine("Введите сдвиг (целое число):");
                int shift = int.Parse(Console.ReadLine());

                string encrypted = Encrypt(input, shift);
                Console.WriteLine($"\nЗашифрованная строка: {encrypted}");

                string decrypted = Decrypt(encrypted, shift);
                Console.WriteLine($"Расшифрованная строка: {decrypted}");

                static string Encrypt(string text, int shift)
                {
                    char[] buffer = text.ToCharArray();
                    for (int i = 0; i < buffer.Length; i++)
                    {
                        char letter = buffer[i];

                        if (char.IsLetter(letter))
                        {
                            char offset = char.IsUpper(letter) ? 'A' : 'a';
                            letter = (char)(((letter + shift - offset) % 26) + offset);
                        }

                        buffer[i] = letter;
                    }

                    return new string(buffer);
                }

                static string Decrypt(string text, int shift)
                {
                    return Encrypt(text, 26 - (shift % 26));
                }
            }

            static void Task_4()
            {
                int[,] matrixA = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
                };

                int[,] matrixB = {
                {9, 8, 7},
                {6, 5, 4},
                {3, 2, 1}
                };

                Console.WriteLine("Матрица A:");
                PrintMatrix(matrixA);
                int scalar = 2;
                Console.WriteLine($"\nМатрица A, умноженная на {scalar}:");
                int[,] scalarMultiplication = MultiplyMatrixByScalar(matrixA, scalar);
                PrintMatrix(scalarMultiplication);

                Console.WriteLine("\nСложение матриц A и B:");
                int[,] matrixSum = AddMatrices(matrixA, matrixB);
                PrintMatrix(matrixSum);

                Console.WriteLine("\nПроизведение матриц A и B:");
                int[,] matrixProduct = MultiplyMatrices(matrixA, matrixB);
                PrintMatrix(matrixProduct);

                static void PrintMatrix(int[,] matrix)
                {
                    for (int i = 0; i < matrix.GetLength(0); i++)
                    {
                        for (int j = 0; j < matrix.GetLength(1); j++)
                        {
                            Console.Write($"{matrix[i, j]}\t");
                        }
                        Console.WriteLine();
                    }
                }

                static int[,] MultiplyMatrixByScalar(int[,] matrix, int scalar)
                {
                    int[,] result = new int[matrix.GetLength(0), matrix.GetLength(1)];
                    for (int i = 0; i < matrix.GetLength(0); i++)
                    {
                        for (int j = 0; j < matrix.GetLength(1); j++)
                        {
                            result[i, j] = matrix[i, j] * scalar;
                        }
                    }
                    return result;
                }

                static int[,] AddMatrices(int[,] matrixA, int[,] matrixB)
                {
                    if (matrixA.GetLength(0) != matrixB.GetLength(0) || matrixA.GetLength(1) != matrixB.GetLength(1))
                    {
                        throw new InvalidOperationException("Матрицы должны быть одного размера для сложения.");
                    }

                    int[,] result = new int[matrixA.GetLength(0), matrixA.GetLength(1)];
                    for (int i = 0; i < matrixA.GetLength(0); i++)
                    {
                        for (int j = 0; j < matrixA.GetLength(1); j++)
                        {
                            result[i, j] = matrixA[i, j] + matrixB[i, j];
                        }
                    }
                    return result;
                }

                static int[,] MultiplyMatrices(int[,] matrixA, int[,] matrixB)
                {
                    if (matrixA.GetLength(1) != matrixB.GetLength(0))
                    {
                        throw new InvalidOperationException("Количество столбцов матрицы A должно совпадать с количеством строк матрицы B для умножения.");
                    }

                    int[,] result = new int[matrixA.GetLength(0), matrixB.GetLength(1)];
                    for (int i = 0; i < matrixA.GetLength(0); i++)
                    {
                        for (int j = 0; j < matrixB.GetLength(1); j++)
                        {
                            result[i, j] = 0;
                            for (int k = 0; k < matrixA.GetLength(1); k++)
                            {
                                result[i, j] += matrixA[i, k] * matrixB[k, j];
                            }
                        }
                    }
                    return result;
                }
            }

            static void Task_5()
            {
                Console.WriteLine("Введите арифметическое выражение (допустимы только операции + и -):");
                string expression = Console.ReadLine();

                try
                {
                    double result = EvaluateExpression(expression);
                    Console.WriteLine($"Результат: {result}");
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Ошибка при вычислении выражения: {ex.Message}");
                }
                static double EvaluateExpression(string expression)
                {
                    expression = expression.Replace(" ", "");

                    double result = 0;
                    int currentNumber = 0;
                    char currentOperation = '+';

                    for (int i = 0; i < expression.Length; i++)
                    {
                        char c = expression[i];

                        if (char.IsDigit(c))
                        {
                            currentNumber = currentNumber * 10 + (c - '0');
                        }

                        if (!char.IsDigit(c) || i == expression.Length - 1)
                        {
                            if (currentOperation == '+')
                            {
                                result += currentNumber;
                            }
                            else if (currentOperation == '-')
                            {
                                result -= currentNumber;
                            }

                            currentOperation = c;
                            currentNumber = 0;
                        }
                    }

                    return result;
                }
            }

            static void Task_6()
            {
                Console.WriteLine("Введите текст:");
                string input = Console.ReadLine();

                string result = CapitalizeSentences(input);
                Console.WriteLine("\nРезультат:");
                Console.WriteLine(result);

                static string CapitalizeSentences(string text)
                {
                    char[] chars = text.ToCharArray();
                    bool capitalizeNext = true;

                    for (int i = 0; i < chars.Length; i++)
                    {
                        if (capitalizeNext && char.IsLetter(chars[i]))
                        {
                            chars[i] = char.ToUpper(chars[i]);
                            capitalizeNext = false;
                        }

                        if (chars[i] == '.' || chars[i] == '!' || chars[i] == '?')
                        {
                            capitalizeNext = true;
                        }
                    }

                    return new string(chars);
                }
            }

            static void Task_7()
            {
                Console.WriteLine("Введите текст:");
                string input = Console.ReadLine();

                Console.WriteLine("Введите недопустимое слово:");
                string forbiddenWord = Console.ReadLine();

                (string processedText, int count) = ReplaceForbiddenWord(input, forbiddenWord);

                Console.WriteLine("\nРезультат работы:");
                Console.WriteLine(processedText);
                Console.WriteLine($"\nСтатистика: {count} замены слова {forbiddenWord}.");

                static (string, int) ReplaceForbiddenWord(string text, string forbiddenWord)
                {
                    int count = 0;
                    string replacement = new string('*', forbiddenWord.Length);
                    string[] words = text.Split(' ');

                    for (int i = 0; i < words.Length; i++)
                    {
                        if (words[i].Contains(forbiddenWord))
                        {
                            words[i] = words[i].Replace(forbiddenWord, replacement);
                            count++;
                        }
                    }

                    return (string.Join(' ', words), count);
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
        static System.Collections.Generic.IEnumerable<(int, int)> GetAllIndices(int rows, int cols)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    yield return (i, j);
                }
            }
        }
    }
}
