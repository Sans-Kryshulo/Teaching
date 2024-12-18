using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WebsiteApp
{
    public class Website
    {
        private string _name;
        private string _url;
        private string _description;
        private string _ipAddress;

        public string Name
        {
            get { return _name; }
            set { _name = value; }
        }

        public string Url
        {
            get { return _url; }
            set { _url = value; }
        }

        public string Description
        {
            get { return _description; }
            set { _description = value; }
        }

        public string IpAddress
        {
            get { return _ipAddress; }
            set { _ipAddress = value; }
        }

        public void InputData()
        {
            Console.WriteLine("Введите название сайта:");
            Name = Console.ReadLine();

            Console.WriteLine("Введите путь к сайту:");
            Url = Console.ReadLine();

            Console.WriteLine("Введите описание сайта:");
            Description = Console.ReadLine();

            Console.WriteLine("Введите IP адрес сайта:");
            IpAddress = Console.ReadLine();
        }

        public void DisplayData()
        {
            Console.WriteLine($"Название сайта: {Name}");
            Console.WriteLine($"Путь к сайту: {Url}");
            Console.WriteLine($"Описание сайта: {Description}");
            Console.WriteLine($"IP адрес сайта: {IpAddress}");
        }
    }
}

