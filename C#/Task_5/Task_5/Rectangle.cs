using System;

namespace ShapeApp
{
    public class Rectangle : Shape
    {
        public double LeftX { get; set; }
        public double LeftY { get; set; }
        public double RightX { get; set; }
        public double RightY { get; set; }

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
    }
}
