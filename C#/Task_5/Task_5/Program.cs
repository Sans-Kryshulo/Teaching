using System;

namespace ShapeApp
{
    class Program
    {
        static void Main(string[] args)
        {
            ShapeCollection shapeCollection = new ShapeCollection();

            shapeCollection.AddShape(new Triangle(3, 4));
            shapeCollection.AddShape(new Rectangle(0, 0, 5, 5));
            shapeCollection.AddShape(new Circle(0, 0, 3));

            Console.WriteLine("Все фигуры:");
            shapeCollection.PrintAllShapes();

            Console.WriteLine("\nОбщая площадь:");
            Console.WriteLine(shapeCollection.CalculateTotalArea());

            Console.WriteLine("\nПрямоугольники:");
            shapeCollection.PrintShapesOfType<Rectangle>();

            Console.WriteLine("\nОбщая площадь кругов:");
            Console.WriteLine(shapeCollection.CalculateTotalAreaOfType<Circle>());
        }
    }
}