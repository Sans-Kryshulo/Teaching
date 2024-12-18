using System;
using System.IO;

namespace ShapeApp
{
    public class Rectangle : Shape
    {
        public double LeftX { get; set; }
        public double LeftY { get; set; }
        public double RightX { get; set; }
        public double RightY { get; set; }

        public Rectangle() { }

        public Rectangle(double leftX, double leftY, double rightX, double rightY)
        {
            LeftX = leftX;
            LeftY = leftY;
            RightX = rightX;
            RightY = rightY;
        }

        public override void Show()
        {
            Console.WriteLine($"Прямоугольник с координатами ({LeftX}, {LeftY}) и ({RightX}, {RightY})");
        }

        public override double Area()
        {
            return Math.Abs((RightX - LeftX) * (RightY - LeftY));
        }

        public override void SaveText(StreamWriter writer)
        {
            writer.WriteLine("Rectangle");
            writer.WriteLine(LeftX);
            writer.WriteLine(LeftY);
            writer.WriteLine(RightX);
            writer.WriteLine(RightY);
        }

        public override void LoadText(StreamReader reader)
        {
            LeftX = double.Parse(reader.ReadLine());
            LeftY = double.Parse(reader.ReadLine());
            RightX = double.Parse(reader.ReadLine());
            RightY = double.Parse(reader.ReadLine());
        }

        public override void SaveBinary(BinaryWriter writer)
        {
            writer.Write("Rectangle");
            writer.Write(LeftX);
            writer.Write(LeftY);
            writer.Write(RightX);
            writer.Write(RightY);
        }

        public override void LoadBinary(BinaryReader reader)
        {
            LeftX = reader.ReadDouble();
            LeftY = reader.ReadDouble();
            RightX = reader.ReadDouble();
            RightY = reader.ReadDouble();
        }
    }
}
