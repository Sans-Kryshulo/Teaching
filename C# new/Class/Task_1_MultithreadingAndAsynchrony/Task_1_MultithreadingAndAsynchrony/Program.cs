using System;
using System.Threading;
using System.Linq;
using System.IO;
using System.Diagnostics;
class Program
{
    static void Main(string[] args)
    {
        bool continueProgram = true;
        while (continueProgram)
        {
            bool continueBank = true;
            Console.WriteLine("Enter the task number from 1 to 7 (0 - exit):");

            while (continueBank == true)
            {
                Console.WriteLine("Enter the number:");

                string numberTask = Console.ReadLine();

                switch (numberTask)
                {
                    case "0":
                        continueBank = false;
                        break;
                    case "1":
                        Thread thread = new Thread(PrintNumbers);
                        thread.Start();
                        thread.Join();
                        Console.WriteLine("The main thread is complete.");
                        ////////////////////
                        continueBank = true;
                        break;
                    case "2":
                        Console.Write("Enter the start of the range: ");
                        int start = int.Parse(Console.ReadLine());
                        Console.Write("Enter the end of the range: ");
                        int end = int.Parse(Console.ReadLine());
                        Thread thread2 = new Thread(() => PrintNumbers2(start, end));
                        thread2.Start();
                        thread2.Join();
                        Console.WriteLine("The main thread is complete.");
                        ////////////////////
                        continueBank = true;
                        break;
                    case "3":
                        Console.Write("Enter the start of the range: ");
                        int start3 = int.Parse(Console.ReadLine());
                        Console.Write("Enter the end of the range: ");
                        int end3 = int.Parse(Console.ReadLine());

                        Console.Write("Enter the number of threads: ");
                        int threadCount = int.Parse(Console.ReadLine());

                        int range = (end3 - start3 + 1) / threadCount;
                        int remaining = (end3 - start3 + 1) % threadCount;

                        Thread[] threads3 = new Thread[threadCount];

                        int currentStart = start3;

                        for (int i = 0; i < threadCount; i++)
                        {
                            int currentEnd = currentStart + range - 1;
                            if (i == threadCount - 1)
                            {
                                currentEnd += remaining;
                            }

                            int threadStart = currentStart;
                            int threadEnd = currentEnd;

                            threads3[i] = new Thread(() => PrintNumbers3(threadStart, threadEnd));
                            threads3[i].Start();

                            currentStart = currentEnd + 1;
                        }

                        foreach (var thread3 in threads3)
                        {
                            thread3.Join();
                        }

                        Console.WriteLine("The main thread is complete.");
                        ////////////////////
                        continueBank = true;
                        break;
                    case "4":
                        int[] numbers4 = Enumerable.Range(1, 10000).ToArray();
                        int max4 = int.MinValue;
                        int min4 = int.MaxValue;
                        double average4 = 0;
                        Thread maxThread4 = new Thread(() =>
                        {
                            max4 = numbers4.Max();
                        });
                        Thread minThread4 = new Thread(() =>
                        {
                            min4 = numbers4.Min();
                        });
                        Thread averageThread4 = new Thread(() =>
                        {
                            average4 = numbers4.Average();
                        });
                        maxThread4.Start();
                        minThread4.Start();
                        averageThread4.Start();
                        maxThread4.Join();
                        minThread4.Join();
                        averageThread4.Join();
                        Console.WriteLine($"Mas: {max4}");
                        Console.WriteLine($"Min: {min4}");
                        Console.WriteLine($"Average: {average4}");
                        Console.WriteLine("The main thread is complete.");
                        ////////////////////
                        continueBank = true;
                        break;
                    case "5":
                        int[] numbers5 = Enumerable.Range(1, 10000).ToArray();
                        int max5 = int.MinValue;
                        int min5 = int.MaxValue;
                        double average5 = 0;
                        Thread maxThread5 = new Thread(() =>
                        {
                            max5 = numbers5.Max();
                        });

                        Thread minThread5 = new Thread(() =>
                        {
                            min5 = numbers5.Min();
                        });

                        Thread averageThread5 = new Thread(() =>
                        {
                            average5 = numbers5.Average();
                        });

                        Thread fileWriterThread5 = new Thread(() =>
                        {
                            string filePath5 = "results.txt";
                            using (StreamWriter writer5 = new StreamWriter(filePath5))
                            {
                                writer5.WriteLine("Set of numbers:");
                                writer5.WriteLine(string.Join(", ", numbers5));
                                writer5.WriteLine();
                                writer5.WriteLine($"Maximum:: {max5}");
                                writer5.WriteLine($"Minimum: {min5}");
                                writer5.WriteLine($"Arithmetic average: {average5}");
                            }
                            Console.WriteLine("The results are saved in a file: results.txt");
                        });

                        maxThread5.Start();
                        minThread5.Start();
                        averageThread5.Start();
                        maxThread5.Join();
                        minThread5.Join();
                        averageThread5.Join();
                        fileWriterThread5.Start();
                        fileWriterThread5.Join();
                        Console.WriteLine("The main thread is complete.");
                        ////////////////////
                        continueBank = true;
                        break;
                    case "6":
                        try
                        {
                            Process process = new Process();
                            string executablePath = @"C:\\Users\\dimar\\source\\repos\\Teaching\\C# new\\Class\\Task_1_MultithreadingAndAsynchrony_WF\\Task_1_MultithreadingAndAsynchrony_WF\\bin\\Debug\\net8.0-windows\\Task_1_MultithreadingAndAsynchrony_WF.exe";
                            process.StartInfo.FileName = executablePath;
                            string arguments = "";
                            process.StartInfo.Arguments = arguments;
                            process.StartInfo.UseShellExecute = false;
                            process.StartInfo.RedirectStandardOutput = true;
                            process.Start();
                            Console.WriteLine("The process is started. Waiting for completion...");
                            process.WaitForExit();
                            int exitCode = process.ExitCode;
                            Console.WriteLine($"The child process ended with the code: {exitCode}");
                            string output = process.StandardOutput.ReadToEnd();
                            if (!string.IsNullOrEmpty(output))
                            {
                                Console.WriteLine("Output of the process:");
                                Console.WriteLine(output);
                            }
                        }
                        catch (Exception ex)
                        {
                            Console.WriteLine($"Error:: {ex.Message}");
                        }
                        ////////////////////
                        continueBank = true;
                        break;
                    case "7":
                        try
                        {
                            Process process = new Process();
                            string executablePath = @"C:\Users\dimar\source\repos\Teaching\C# new\Class\Task_1_MultithreadingAndAsynchrony_WF2\Task_1_MultithreadingAndAsynchrony_WF2\bin\Debug\net8.0-windows\\Task_1_MultithreadingAndAsynchrony_WF2.exe";
                            process.StartInfo.FileName = executablePath;
                            string arguments = "";
                            process.StartInfo.Arguments = arguments;
                            process.StartInfo.UseShellExecute = false;
                            process.StartInfo.RedirectStandardOutput = true;
                            process.Start();
                            Console.WriteLine("The process is started. Waiting for completion...");
                            process.WaitForExit();
                            int exitCode = process.ExitCode;
                            Console.WriteLine($"The child process ended with the code: {exitCode}");
                            string output = process.StandardOutput.ReadToEnd();
                            if (!string.IsNullOrEmpty(output))
                            {
                                Console.WriteLine("Output of the process:");
                                Console.WriteLine(output);
                            }
                        }
                        catch (Exception ex)
                        {
                            Console.WriteLine($"Error:: {ex.Message}");
                        }
                        ////////////////////
                        continueBank = true;
                        break;
                    default:
                        Console.WriteLine("Error: invalid request number.");
                        continueBank = true;
                        break;
                }

            }
            continueProgram = AskToContinue();
        }

        static void PrintNumbers()
        {
            for (int i = 0; i <= 50; i++)
            {
                Console.WriteLine(i);
                Thread.Sleep(100);
            }
        }

        static void PrintNumbers2(int start, int end)
        {
            for (int i = start; i <= end; i++)
            {
                Console.WriteLine(i);
                Thread.Sleep(100);
            }
        }

        static void PrintNumbers3(int start, int end)
        {
            for (int i = start; i <= end; i++)
            {
                Console.WriteLine($"Потік {Thread.CurrentThread.ManagedThreadId}: {i}");
                Thread.Sleep(100);
            }
        }

        static bool AskToContinue()
        {
            Console.WriteLine("Exit the program? (Y/N)");
            string response = Console.ReadLine().Trim().ToUpper();

            while (response != "Y" && response != "N")
            {
                Console.WriteLine("Error: Enter Y to continue or N to exit.");
                response = Console.ReadLine().Trim().ToUpper();
            }

            return response == "N";
        }
    }

}