using System;
using System.Collections.Generic;
using System.Linq;

namespace FirmApp
{
    public static class Queries
    {
        public static void ExecuteQueries(List<Firm> firms)
        {
            Console.WriteLine("All firms:");
            firms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms with 'Food' in name:");
            var foodFirms = firms.Where(f => f.Name.Contains("Food")).ToList();
            foodFirms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms in Marketing:");
            var marketingFirms = firms.Where(f => f.BusinessProfile == "Marketing").ToList();
            marketingFirms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms in Marketing or IT:");
            var marketingOrITFirms = firms.Where(f => f.BusinessProfile == "Marketing" || f.BusinessProfile == "IT").ToList();
            marketingOrITFirms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms with employees > 100:");
            var largeFirms = firms.Where(f => f.EmployeeCount > 100).ToList();
            largeFirms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms with 100-300 employees:");
            var midSizeFirms = firms.Where(f => f.EmployeeCount >= 100 && f.EmployeeCount <= 300).ToList();
            midSizeFirms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms in London:");
            var londonFirms = firms.Where(f => f.Address.Contains("London")).ToList();
            londonFirms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms with director surname 'White':");
            var whiteDirectorFirms = firms.Where(f => f.Director.Contains("White")).ToList();
            whiteDirectorFirms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms founded more than 2 years ago:");
            var oldFirms = firms.Where(f => (DateTime.Now - f.FoundedDate).TotalDays > 2 * 365).ToList();
            oldFirms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms founded exactly 123 days ago:");
            var specificAgeFirms = firms.Where(f => (DateTime.Now - f.FoundedDate).TotalDays == 123).ToList();
            specificAgeFirms.ForEach(f => Console.WriteLine(f));
        }

        public static void ExecuteMethodSyntaxQueries(List<Firm> firms)
        {
            Console.WriteLine("All firms:");
            firms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms with 'Food' in name:");
            var foodFirms = firms.Where(f => f.Name.Contains("Food")).ToList();
            foodFirms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms in Marketing:");
            var marketingFirms = firms.Where(f => f.BusinessProfile == "Marketing").ToList();
            marketingFirms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms in Marketing or IT:");
            var marketingOrITFirms = firms.Where(f => f.BusinessProfile == "Marketing" || f.BusinessProfile == "IT").ToList();
            marketingOrITFirms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms with employees > 100:");
            var largeFirms = firms.Where(f => f.EmployeeCount > 100).ToList();
            largeFirms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms with 100-300 employees:");
            var midSizeFirms = firms.Where(f => f.EmployeeCount >= 100 && f.EmployeeCount <= 300).ToList();
            midSizeFirms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms in London:");
            var londonFirms = firms.Where(f => f.Address.Contains("London")).ToList();
            londonFirms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms with director surname 'White':");
            var whiteDirectorFirms = firms.Where(f => f.Director.Contains("White")).ToList();
            whiteDirectorFirms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms founded more than 2 years ago:");
            var oldFirms = firms.Where(f => (DateTime.Now - f.FoundedDate).TotalDays > 2 * 365).ToList();
            oldFirms.ForEach(f => Console.WriteLine(f));

            Console.WriteLine("\nFirms founded exactly 123 days ago:");
            var specificAgeFirms = firms.Where(f => (DateTime.Now - f.FoundedDate).TotalDays == 123).ToList();
            specificAgeFirms.ForEach(f => Console.WriteLine(f));
        }
    }
}
