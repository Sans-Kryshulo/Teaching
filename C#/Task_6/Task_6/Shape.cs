using System.IO;

namespace ShapeApp
{
    public abstract class Shape
    {
        public abstract void Show();
        public abstract double Area();

        public abstract void SaveText(StreamWriter writer);
        public abstract void LoadText(StreamReader reader);

        public abstract void SaveBinary(BinaryWriter writer);
        public abstract void LoadBinary(BinaryReader reader);
    }
}
