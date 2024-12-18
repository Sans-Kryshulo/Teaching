using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SquareApp
{
    public class SquareDrawer
    {
        public static void DrawSquare(int sideLength, char symbol)
        {
            if (sideLength <= 0)
            {
                throw new ArgumentException("Длина стороны квадрата должна быть больше нуля.");
            }

            for (int i = 0; i < sideLength; i++)
            {
                for (int j = 0; j < sideLength; j++)
                {
                    Console.Write(symbol);
                }
                Console.WriteLine();
            }
        }
    }
}
