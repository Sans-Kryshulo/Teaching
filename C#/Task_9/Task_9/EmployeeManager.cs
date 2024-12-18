using System;
using System.Collections.Generic;

namespace EmployeeManagementApp
{
    public class EmployeeManager
    {
        private Dictionary<string, string> employeeData;

        public EmployeeManager()
        {
            employeeData = new Dictionary<string, string>();
        }

        public void AddEmployee(string login, string password)
        {
            if (!employeeData.ContainsKey(login))
            {
                employeeData.Add(login, password);
                Console.WriteLine($"Сотрудник с логином '{login}' был успешно добавлен.");
            }
            else
            {
                Console.WriteLine($"Логин '{login}' уже существует. Используйте другой логин.");
            }
        }

        public void RemoveEmployee(string login)
        {
            if (employeeData.ContainsKey(login))
            {
                employeeData.Remove(login);
                Console.WriteLine($"Сотрудник с логином '{login}' был успешно удален.");
            }
            else
            {
                Console.WriteLine($"Сотрудник с логином '{login}' не найден.");
            }
        }

        public void UpdateEmployee(string oldLogin, string newLogin, string newPassword)
        {
            if (employeeData.ContainsKey(oldLogin))
            {
                employeeData.Remove(oldLogin);
                employeeData.Add(newLogin, newPassword);
                Console.WriteLine($"Информация о сотруднике с логином '{oldLogin}' была успешно обновлена.");
            }
            else
            {
                Console.WriteLine($"Сотрудник с логином '{oldLogin}' не найден.");
            }
        }

        public string GetPassword(string login)
        {
            if (employeeData.TryGetValue(login, out string password))
            {
                return password;
            }
            else
            {
                Console.WriteLine($"Сотрудник с логином '{login}' не найден.");
                return null;
            }
        }
    }
}

