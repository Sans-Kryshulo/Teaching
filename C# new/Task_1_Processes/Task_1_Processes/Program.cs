using System;
using System.Diagnostics;
using System.Diagnostics.Metrics;

class Program
{
    static void Main(string[] args)
    {
        bool continueProgram = true;
        while (continueProgram)
        {
            bool continueBank = true;
            Console.WriteLine("Enter the task number from 1 to 4 (0 - exit):");

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
                        try
                        {
                            string editorPath = "notepad.exe";
                            string documentPath = @"C:\\Users\\dimar\\source\\repos\\Teaching\\C# new\\Task_1_Processes\\Child_process";

                            Process process = new Process
                            {
                                StartInfo = new ProcessStartInfo
                                {
                                    FileName = editorPath,
                                    Arguments = documentPath,
                                    UseShellExecute = false
                                }
                            };

                            process.Start();
                            Console.WriteLine("The text editor is running. Waiting for completion...");
                            process.WaitForExit();
                            int exitCode = process.ExitCode;
                            Console.WriteLine($"The process ended with the code: {exitCode}");
                        }
                        catch (Exception ex)
                        {
                            Console.WriteLine($"Error: {ex.Message}");
                        }

                        ////////////////////
                        continueBank = true;
                        break;
                    case "2":
                        try
                        {
                            Process process = new Process();
                            Console.WriteLine("Enter the path to the executable file of the child process:");
                            string executablePath = Console.ReadLine();
                            process.StartInfo.FileName = executablePath;

                            Console.WriteLine("Enter arguments for the process (or leave blank):");
                            string arguments = Console.ReadLine();
                            process.StartInfo.Arguments = arguments;
                            process.StartInfo.UseShellExecute = false;
                            process.StartInfo.RedirectStandardOutput = true;
                            process.Start();

                            Console.WriteLine("The process is started. Select an action:");
                            Console.WriteLine("1. Wait for the process to complete");
                            Console.WriteLine("2. Force the process to end");
                            Console.WriteLine("Enter number:");
                            string choice = Console.ReadLine();

                            if (choice == "1")
                            {
                                Console.WriteLine("Waiting for the process to complete...");
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
                            else if (choice == "2")
                            {
                                Console.WriteLine("Forced termination of the process...");

                                if (!process.HasExited)
                                {
                                    process.Kill();
                                    Console.WriteLine("The process was forcibly terminated.");
                                }
                                else
                                {
                                    Console.WriteLine("The process has already been completed.");
                                }
                            }
                            else
                            {
                                Console.WriteLine("Wrong choice.");
                            }
                        }
                        catch (Exception ex)
                        {
                            Console.WriteLine($"Error: {ex.Message}");
                        }

                        ////////////////////
                        continueBank = true;
                        break;
                    case "3":
                        try
                        {
                            Console.WriteLine("Enter the path to the child process executable:");
                            string executablePath = Console.ReadLine();

                            Console.WriteLine("Enter the first number:");
                            string number1 = Console.ReadLine();

                            Console.WriteLine("Enter the second number:");
                            string number2 = Console.ReadLine();

                            Console.WriteLine("Enter the operation (+, -, *, /):");
                            string operation = Console.ReadLine();
                            string arguments = $"{number1} {number2} {operation}";

                            Process process = new Process
                            {
                                StartInfo = new ProcessStartInfo
                                {
                                    FileName = executablePath,
                                    Arguments = arguments,
                                    UseShellExecute = false,
                                    RedirectStandardOutput = true
                                }
                            };

                            process.Start();
                            string output = process.StandardOutput.ReadToEnd();
                            process.WaitForExit();
                            Console.WriteLine("The result of the child process:");
                            Console.WriteLine(output);
                        }
                        catch (Exception ex)
                        {
                            Console.WriteLine($"Error: {ex.Message}");
                        }

                        ////////////////////
                        continueBank = true;
                        break;
                    case "4":
                        try
                        {
                            Console.WriteLine("Enter the file path:");
                            string filePath = Console.ReadLine();

                            Console.WriteLine("Enter a word to search for:");
                            string word = Console.ReadLine();

                            Console.WriteLine("Enter the path to the child process executable:");
                            string executablePath = Console.ReadLine();
                            string arguments = $"\"{filePath}\" \"{word}\"";

                            Process process = new Process
                            {
                                StartInfo = new ProcessStartInfo
                                {
                                    FileName = executablePath,
                                    Arguments = arguments,
                                    UseShellExecute = false,
                                    RedirectStandardOutput = true
                                }
                            };

                            process.Start();
                            string output = process.StandardOutput.ReadToEnd();
                            process.WaitForExit();
                            Console.WriteLine("The result of the child process:");
                            Console.WriteLine(output);
                        }
                        catch (Exception ex)
                        {
                            Console.WriteLine($"Error: {ex.Message}");
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