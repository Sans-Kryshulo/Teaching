using System;
using System.IO;
using System.Text.RegularExpressions;

class Program
{
    static void Main(string[] args)
    {
        string folderPath = @"C:\Users\dimar\OneDrive\Документи\Paradox Interactive\Hearts of Iron IV\mod\Equestria_at_War\history\states"; // The actual path to the file folder
        string[] files = Directory.GetFiles(folderPath, "*.txt");

        foreach (string file in files)
        {
            string content = File.ReadAllText(file);
            string pattern = @"(manpower\s*=\s*)(\d+)";
            // Multiply the workforce value by 4, but you can choose whichever number and mathematical expression you want
            string updatedContent = Regex.Replace(content, pattern, m =>
            {
                int manpowerValue = int.Parse(m.Groups[2].Value);
                return m.Groups[1].Value + (manpowerValue * 4);
            });
            File.WriteAllText(file, updatedContent);
        }
        Console.WriteLine("Manpower values updated successfully.");
    }
}