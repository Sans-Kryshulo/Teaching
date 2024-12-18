using System;
using System.IO;

namespace ShapeApp
{
    public class Circle : Shape
    {
        public double CenterX { get; set; }
        public double CenterY { get; set; }
        public double Radius { get; set; }

        public Circle() { }

        public Circle(double centerX, double centerY, double radius)
        {
            CenterX = centerX;
            CenterY = centerY;
            Radius = radius;
        }

        public override void Show()
        {
            Console.WriteLine($"Круг с центром в ({CenterX}, {CenterY}) и радиусом {Radius}");
        }

        public override double Area()
        {
            return Math.PI * Radius * Radius;
        }

        public override void SaveText(StreamWriter writer)
        {
            writer.WriteLine("Circle");
            writer.WriteLine(CenterX);
            writer.WriteLine(CenterY);
            writer.WriteLine(Radius);
        }

        public override void LoadText(StreamReader reader)
        {
            CenterX = double.Parse(reader.ReadLine());
            CenterY = double.Parse(reader.ReadLine());
            Radius = double.Parse(reader.ReadLine());
        }

        public override void SaveBinary(BinaryWriter writer)
        {
            writer.Write("Circle");
            writer.Write(CenterX);
            writer.Write(CenterY);
            writer.Write(Radius);
        }

        public override void LoadBinary(BinaryReader reader)
        {
            CenterX = reader.ReadDouble();
            CenterY = reader.ReadDouble();
            Radius = reader.ReadDouble();
        }
    }
}
