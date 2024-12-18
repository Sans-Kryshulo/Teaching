using System;
using System.Collections.Generic;
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
    }
}