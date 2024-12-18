using System;

namespace ShapeApp
{
    public class Triangle : Shape
    {
        public double SideA { get; set; }
        public double SideB { get; set; }

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
    }
}
