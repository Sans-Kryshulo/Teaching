using System;

namespace AcademyApp
{
    public class Person
    {
        public string Name { get; set; }
        public string Surname { get; set; }
        public int Age { get; set; }
        public string Phone { get; set; }

        public Person() { }

        public Person(string name, string surname, int age, string phone)
        {
            Name = name;
            Surname = surname;
            Age = age;
            Phone = phone;
        }

        public virtual void Print()
        {
            Console.WriteLine($"Имя: {Name}, Фамилия: {Surname}, Возраст: {Age}, Телефон: {Phone}");
        }
    }
}
