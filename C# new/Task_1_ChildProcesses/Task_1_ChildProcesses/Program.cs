using System;

class ChildProgram
{
    static void Main(string[] args)
    {
        try
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Three arguments must be passed: number1, number2, operation.");
                return;
            }

            int number1 = int.Parse(args[0]);
            int number2 = int.Parse(args[1]);
            string operation = args[2];

            int result = operation switch
            {
                "+" => number1 + number2,
                "-" => number1 - number2,
                "*" => number1 * number2,
                "/" when number2 != 0 => number1 / number2,
                "/" => throw new DivideByZeroException("Division by zero."),
                _ => throw new InvalidOperationException("Unsupported operation.")
            };

            Console.WriteLine($"Arguments: {number1}, {number2}, {operation}");
            Console.WriteLine($"Result {result}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
    }
}
