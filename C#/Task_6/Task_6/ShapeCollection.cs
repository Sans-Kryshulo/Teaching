using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ShapeApp
{
    public class ShapeCollection
    {
        private List<Shape> shapes = new List<Shape>();

        public void AddShape(Shape shape)
        {
            shapes.Add(shape);
        }

        public void RemoveShape(Shape shape)
        {
            shapes.Remove(shape);
        }

        public void PrintAllShapes()
        {
            foreach (var shape in shapes)
            {
                shape.Show();
            }
        }

        public void PrintShapesOfType<T>() where T : Shape
        {
            foreach (var shape in shapes.OfType<T>())
            {
                shape.Show();
            }
        }

        public double CalculateTotalArea()
        {
            return shapes.Sum(shape => shape.Area());
        }

        public double CalculateTotalAreaOfType<T>() where T : Shape
        {
            return shapes.OfType<T>().Sum(shape => shape.Area());
        }

        public void SaveShapesToTextFile(string filePath)
        {
            using (StreamWriter writer = new StreamWriter(filePath))
            {
                foreach (var shape in shapes)
                {
                    shape.SaveText(writer);
                }
            }
        }

        public void LoadShapesFromTextFile(string filePath)
        {
            shapes.Clear();
            using (StreamReader reader = new StreamReader(filePath))
            {
                while (!reader.EndOfStream)
                {
                    string shapeType = reader.ReadLine();
                    Shape shape = shapeType switch
                    {
                        "Triangle" => new Triangle(),
                        "Rectangle" => new Rectangle(),
                        "Circle" => new Circle(),
                        _ => throw new InvalidOperationException("Unknown shape type")
                    };
                    shape.LoadText(reader);
                    shapes.Add(shape);
                }
            }
        }

        public void SaveShapesToBinaryFile(string filePath)
        {
            using (BinaryWriter writer = new BinaryWriter(File.Open(filePath, FileMode.Create)))
            {
                foreach (var shape in shapes)
                {
                    shape.SaveBinary(writer);
                }
            }
        }

        public void LoadShapesFromBinaryFile(string filePath)
        {
            shapes.Clear();
            using (BinaryReader reader = new BinaryReader(File.Open(filePath, FileMode.Open)))
            {
                while (reader.BaseStream.Position != reader.BaseStream.Length)
                {
                    string shapeType = reader.ReadString();
                    Shape shape = shapeType switch
                    {
                        "Triangle" => new Triangle(),
                        "Rectangle" => new Rectangle(),
                        "Circle" => new Circle(),
                        _ => throw new InvalidOperationException("Unknown shape type")
                    };
                    shape.LoadBinary(reader);
                    shapes.Add(shape);
                }
            }
        }
    }
}
