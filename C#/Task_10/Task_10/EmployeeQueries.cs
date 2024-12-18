using System;
using System.Collections.Generic;
using System.Linq;

namespace FirmApp
{
    public static class EmployeeQueries
    {
        public static void ExecuteEmployeeQueries(List<Firm> firms)
        {
            Console.WriteLine("\nEmployees of a specific firm (e.g., TechFood):");
            var firmName = "TechFood";
            var specificFirmEmployees = firms
                .FirstOrDefault(f => f.Name == firmName)?
                .Employees;
            specificFirmEmployees?.ForEach(e => Console.WriteLine(e));

            Console.WriteLine("\nEmployees with salary > 50000:");
            var highSalaryEmployees = firms
                .SelectMany(f => f.Employees)
                .Where(e => e.Salary > 50000);
            foreach (var emp in highSalaryEmployees)
                Console.WriteLine(emp);

            Console.WriteLine("\nEmployees with position 'Manager':");
            var managers = firms
                .SelectMany(f => f.Employees)
                .Where(e => e.Position == "Manager");
            foreach (var emp in managers)
                Console.WriteLine(emp);

            Console.WriteLine("\nEmployees with phone starting with '23':");
            var phone23Employees = firms
                .SelectMany(f => f.Employees)
                .Where(e => e.Phone.StartsWith("23"));
            foreach (var emp in phone23Employees)
                Console.WriteLine(emp);

            Console.WriteLine("\nEmployees with email starting with 'di':");
            var emailDiEmployees = firms
                .SelectMany(f => f.Employees)
                .Where(e => e.Email.StartsWith("di", StringComparison.OrdinalIgnoreCase));
            foreach (var emp in emailDiEmployees)
                Console.WriteLine(emp);

            Console.WriteLine("\nEmployees with name 'Lionel':");
            var lionelEmployees = firms
                .SelectMany(f => f.Employees)
                .Where(e => e.FullName.Contains("Lionel"));
            foreach (var emp in lionelEmployees)
                Console.WriteLine(emp);
        }
    }
}
