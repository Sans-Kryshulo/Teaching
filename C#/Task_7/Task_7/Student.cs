using System;
using System.Collections;

namespace AcademyApp
{
    public class Student : Person, IComparable<Student>
    {
        public double Average { get; set; }
        public int Number_Of_Group { get; set; }

        public Student() { }

        public Student(string name, string surname, int age, string phone, double average, int numberOfGroup)
            : base(name, surname, age, phone)
        {
            Average = average;
            Number_Of_Group = numberOfGroup;
        }

        public override void Print()
        {
            base.Print();
            Console.WriteLine($"Средний балл: {Average}, Номер группы: {Number_Of_Group}");
        }

        public int CompareTo(Student other)
        {
            if (other == null) return 1;
            return Average.CompareTo(other.Average);
        }

        public class CompareBySurname : IComparer<Student>
        {
            public int Compare(Student x, Student y)
            {
                return string.Compare(x.Surname, y.Surname);
            }
        }

        public class CompareByAge : IComparer<Student>
        {
            public int Compare(Student x, Student y)
            {
                return x.Age.CompareTo(y.Age);
            }
        }
    }
}
