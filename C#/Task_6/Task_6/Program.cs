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

            string textFilePath = "shapes.txt";
            string binaryFilePath = "shapes.bin";

            // Сохранение и загрузка из текстового файла
            shapeCollection.SaveShapesToTextFile(textFilePath);
            Console.WriteLine("\nФигуры сохранены в текстовый файл.");

            shapeCollection.LoadShapesFromTextFile(textFilePath);
            Console.WriteLine("\nФигуры загружены из текстового файла:");
            shapeCollection.PrintAllShapes();

            // Сохранение и загрузка из бинарного файла
            shapeCollection.SaveShapesToBinaryFile(binaryFilePath);
            Console.WriteLine("\nФигуры сохранены в бинарный файл.");

            shapeCollection.LoadShapesFromBinaryFile(binaryFilePath);
            Console.WriteLine("\nФигуры загружены из бинарного файла:");
            shapeCollection.PrintAllShapes();

            Console.WriteLine("\nОбщая площадь всех фигур:");
            Console.WriteLine(shapeCollection.CalculateTotalArea());

            Console.WriteLine("\nОбщая площадь всех прямоугольников:");
            Console.WriteLine(shapeCollection.CalculateTotalAreaOfType<Rectangle>());
        }
    }
}
