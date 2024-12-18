using System;
using System.Collections;
using System.Collections.Generic;

namespace AcademyApp
{
    public class Academy_Group : ICloneable
    {
        private List<Student> students;

        public Academy_Group()
        {
            students = new List<Student>();
        }

        public void Add(Student student)
        {
            students.Add(student);
        }

        public void Remove(string surname)
        {
            students.RemoveAll(s => s.Surname == surname);
        }

        public void Edit(string surname, Student newStudentData)
        {
            for (int i = 0; i < students.Count; i++)
            {
                if (students[i].Surname == surname)
                {
                    students[i] = newStudentData;
                    break;
                }
            }
        }

        public void Print()
        {
            foreach (var student in students)
            {
                student.Print();
            }
        }

        public void Sort(IComparer<Student> comparer)
        {
            students.Sort(comparer);
        }

        public void Sort()
        {
            students.Sort();
        }

        public void Save(string fileName)
        {
            using (var writer = new System.IO.BinaryWriter(System.IO.File.Open(fileName, System.IO.FileMode.Create)))
            {
                writer.Write(students.Count);
                foreach (var student in students)
                {
                    writer.Write(student.Name);
                    writer.Write(student.Surname);
                    writer.Write(student.Age);
                    writer.Write(student.Phone);
                    writer.Write(student.Average);
                    writer.Write(student.Number_Of_Group);
                }
            }
        }

        public void Load(string fileName)
        {
            students.Clear();
            using (var reader = new System.IO.BinaryReader(System.IO.File.Open(fileName, System.IO.FileMode.Open)))
            {
                int count = reader.ReadInt32();
                for (int i = 0; i < count; i++)
                {
                    string name = reader.ReadString();
                    string surname = reader.ReadString();
                    int age = reader.ReadInt32();
                    string phone = reader.ReadString();
                    double average = reader.ReadDouble();
                    int numberOfGroup = reader.ReadInt32();

                    students.Add(new Student(name, surname, age, phone, average, numberOfGroup));
                }
            }
        }

        public Student Search(string surname)
        {
            return students.Find(s => s.Surname == surname);
        }

        public object Clone()
        {
            var newGroup = new Academy_Group();
            foreach (var student in students)
            {
                var clonedStudent = new Student(student.Name, student.Surname, student.Age, student.Phone, student.Average, student.Number_Of_Group);
                newGroup.Add(clonedStudent);
            }
            return newGroup;
        }
    }
}
