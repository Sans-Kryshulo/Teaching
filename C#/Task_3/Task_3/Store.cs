using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StoreApp
{
    public class Store
    {
        private string _name;
        private string _address;
        private string _description;
        private string _contactPhone;
        private string _contactEmail;

        public string Name
        {
            get { return _name; }
            set { _name = value; }
        }

        public string Address
        {
            get { return _address; }
            set { _address = value; }
        }

        public string Description
        {
            get { return _description; }
            set { _description = value; }
        }

        public string ContactPhone
        {
            get { return _contactPhone; }
            set { _contactPhone = value; }
        }

        public string ContactEmail
        {
            get { return _contactEmail; }
            set { _contactEmail = value; }
        }

        public void InputData()
        {
            Console.WriteLine("Введите название магазина:");
            Name = Console.ReadLine();

            Console.WriteLine("Введите адрес магазина:");
            Address = Console.ReadLine();

            Console.WriteLine("Введите описание профиля магазина:");
            Description = Console.ReadLine();

            Console.WriteLine("Введите контактный телефон:");
            ContactPhone = Console.ReadLine();

            Console.WriteLine("Введите контактный e-mail:");
            ContactEmail = Console.ReadLine();
        }

        public void DisplayData()
        {
            Console.WriteLine($"Название магазина: {Name}");
            Console.WriteLine($"Адрес магазина: {Address}");
            Console.WriteLine($"Описание профиля магазина: {Description}");
            Console.WriteLine($"Контактный телефон: {ContactPhone}");
            Console.WriteLine($"Контактный e-mail: {ContactEmail}");
        }
    }
}

