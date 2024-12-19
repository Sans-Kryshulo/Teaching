using System;
using System.IO;

class ChildProgram
{
    static void Main(string[] args)
    {
        try
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Two arguments must be passed: the file path and the word to search for.");
                return;
            }

            string filePath = args[0];
            string word = args[1];

            if (!File.Exists(filePath))
            {
                Console.WriteLine($"File not found: {filePath}");
                return;
            }

            string content = File.ReadAllText(filePath);
            int count = 0;
            int index = 0;
            while ((index = content.IndexOf(word, index, StringComparison.OrdinalIgnoreCase)) != -1)
            {
                count++;
                index += word.Length;
            }

            Console.WriteLine($"Word '{word}' meets {count} time(s) in the file {filePath}.");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
    }
}
