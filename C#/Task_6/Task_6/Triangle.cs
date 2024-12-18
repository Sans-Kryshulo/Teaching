using System;
using System.IO;

namespace ShapeApp
{
    public class Triangle : Shape
    {
        public double SideA { get; set; }
        public double SideB { get; set; }

        public Triangle() { }

        public Triangle(double sideA, double sideB)
        {
            SideA = sideA;
            SideB = sideB;
        }

        public override void Show()
        {
            Console.WriteLine($"Треугольник с катетами A={SideA} и B={SideB}");
        }

        public override double Area()
        {
            return 0.5 * SideA * SideB;
        }

        public override void SaveText(StreamWriter writer)
        {
            writer.WriteLine("Triangle");
            writer.WriteLine(SideA);
            writer.WriteLine(SideB);
        }

        public override void LoadText(StreamReader reader)
        {
            SideA = double.Parse(reader.ReadLine());
            SideB = double.Parse(reader.ReadLine());
        }

        public override void SaveBinary(BinaryWriter writer)
        {
            writer.Write("Triangle");
            writer.Write(SideA);
            writer.Write(SideB);
        }

        public override void LoadBinary(BinaryReader reader)
        {
            SideA = reader.ReadDouble();
            SideB = reader.ReadDouble();
        }
    }
}

