using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MagazineApp
{
    public class Magazine
    {
        private string _title;
        private int _yearFounded;
        private string _description;
        private string _contactPhone;
        private string _contactEmail;
        private int year;

        public string Title
        {
            get { return _title; }
            set { _title = value; }
        }

        public int YearFounded
        {
            get { return _yearFounded; }
            set { _yearFounded = value; }
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
            Console.WriteLine("Введите название журнала:");
            Title = Console.ReadLine();

            Console.WriteLine("Введите год основания:");
            while (!int.TryParse(Console.ReadLine(), out int year))
            {
                Console.WriteLine("Некорректный ввод. Введите год основания:");
            }
            YearFounded = year;

            Console.WriteLine("Введите описание журнала:");
            Description = Console.ReadLine();

            Console.WriteLine("Введите контактный телефон:");
            ContactPhone = Console.ReadLine();

            Console.WriteLine("Введите контактный e-mail:");
            ContactEmail = Console.ReadLine();
        }

        public void DisplayData()
        {
            Console.WriteLine($"Название журнала: {Title}");
            Console.WriteLine($"Год основания: {YearFounded}");
            Console.WriteLine($"Описание журнала: {Description}");
            Console.WriteLine($"Контактный телефон: {ContactPhone}");
            Console.WriteLine($"Контактный e-mail: {ContactEmail}");
        }
    }
}
