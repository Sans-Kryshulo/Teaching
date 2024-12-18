using System;

namespace ShapeApp
{
    public class Circle : Shape
    {
        public double CenterX { get; set; }
        public double CenterY { get; set; }
        public double Radius { get; set; }

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
    }
}

