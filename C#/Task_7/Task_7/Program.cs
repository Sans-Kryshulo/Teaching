using System;

namespace AcademyApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var group = new Academy_Group();

            group.Add(new Student("Иван", "Иванов", 20, "111-11-11", 4.5, 101));
            group.Add(new Student("Петр", "Петров", 21, "222-22-22", 3.7, 101));
            group.Add(new Student("Сергей", "Сергеев", 19, "333-33-33", 4.2, 101));

            Console.WriteLine("Все студенты:");
            group.Print();

            Console.WriteLine("\nСортировка по фамилии:");
            group.Sort(new Student.CompareBySurname());
            group.Print();

            Console.WriteLine("\nСортировка по возрасту:");
            group.Sort(new Student.CompareByAge());
            group.Print();

            group.Save("group.dat");

            var newGroup = new Academy_Group();
            newGroup.Load("group.dat");

            Console.WriteLine("\nЗагруженные студенты:");
            newGroup.Print();

            var foundStudent = group.Search("Иванов");
            if (foundStudent != null)
            {
                Console.WriteLine("\nНайден студент:");
                foundStudent.Print();
            }
            else
            {
                Console.WriteLine("\nСтудент не найден.");
            }

            var clonedGroup = (Academy_Group)group.Clone();
            Console.WriteLine("\nКлонированная группа:");
            clonedGroup.Print();
        }
    }
}
