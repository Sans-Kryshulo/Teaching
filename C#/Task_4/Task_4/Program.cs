using System;
using System.Collections.Generic;

public class Bank
{
    public List<ATM> ATMs { get; private set; }

    public Bank()
    {
        ATMs = new List<ATM>();
    }

    public void InitializeATMs(int numberOfATMs)
    {
        for (int i = 0; i < numberOfATMs; i++)
        {
            ATMs.Add(new ATM());
        }
    }

    public decimal GetTotalMoneyInATMs()
    {
        decimal total = 0;
        foreach (var atm in ATMs)
        {
            total += atm.GetTotalMoney();
        }
        return total;
    }
}

public class ATM
{
    private Dictionary<int, int> banknotes;
    private readonly int[] denominations = { 1, 2, 5, 10, 20, 50, 100, 200, 500 };
    private const int MaxBanknotesToDispense = 40;

    public ATM()
    {
        banknotes = new Dictionary<int, int>();
        foreach (var denom in denominations)
        {
            banknotes[denom] = 0;
        }
    }

    public void LoadMoney(Dictionary<int, int> initialBanknotes)
    {
        foreach (var kvp in initialBanknotes)
        {
            if (!denominations.Contains(kvp.Key))
            {
                throw new InvalidDenominationException($"Неверный номинал: {kvp.Key}");
            }
            banknotes[kvp.Key] += kvp.Value;
        }
    }

    public void InsertMoney(Dictionary<int, int> insertedBanknotes)
    {
        LoadMoney(insertedBanknotes);
    }

    public void WithdrawMoney(int amount)
    {
        if (amount <= 0)
        {
            throw new InvalidOperationException("Сумма для снятия должна быть больше нуля.");
        }

        var result = new Dictionary<int, int>();
        int totalBanknotes = 0;
        foreach (var denom in denominations)
        {
            while (amount >= denom && banknotes[denom] > 0)
            {
                if (!result.ContainsKey(denom))
                {
                    result[denom] = 0;
                }

                result[denom]++;
                banknotes[denom]--;
                amount -= denom;
                totalBanknotes++;

                if (totalBanknotes > MaxBanknotesToDispense)
                {
                    throw new DispenseLimitExceededException("Превышено максимальное количество банкнот для выдачи.");
                }
            }
        }

        if (amount > 0)
        {
            throw new InsufficientFundsException("В банкомате недостаточно средств для завершения транзакции.");
        }
    }

    public decimal GetTotalMoney()
    {
        decimal total = 0;
        foreach (var kvp in banknotes)
        {
            total += kvp.Key * kvp.Value;
        }
        return total;
    }
}

public class InvalidDenominationException : Exception
{
    public InvalidDenominationException(string message) : base(message) { }
}

public class InsufficientFundsException : Exception
{
    public InsufficientFundsException(string message) : base(message) { }
}

public class DispenseLimitExceededException : Exception
{
    public DispenseLimitExceededException(string message) : base(message) { }
}

class Program
{
    static void Main(string[] args)
    {
        Bank bank = new Bank();
        int Atm = 2;
        bank.InitializeATMs(Atm);

        var atm1 = bank.ATMs[0];
        atm1.LoadMoney(new Dictionary<int, int>
        {
            { 100, 10 },
            { 50, 20 },
            { 20, 30 },
            { 10, 50 },
            { 5, 100 }
        });

        var atm2 = bank.ATMs[1];
        atm2.LoadMoney(new Dictionary<int, int>
        {
            { 200, 5 },
            { 100, 10 },
            { 50, 10 }
        });

        bool continueProgram = true;
        

        while (continueProgram)
        {
            bool continueBank = true;
            Console.WriteLine("Что вы хотите сделать?");
            Console.WriteLine("1. Узнать общую сумму денег в банкоматах банка;");
            Console.WriteLine("2. Снять деньги из банкомата;");
            Console.WriteLine("3. Показать меню;");
            Console.WriteLine("4. Выйти из программы.");
            
            while (continueBank == true)
            {
                Console.WriteLine("Укажите номер:");

                string numberTask = Console.ReadLine();

                switch (numberTask)
                {
                    case "1":
                        Task_1(bank);
                        continueBank = true;
                        break;
                    case "2":
                        Task_2(Atm, atm1, atm2);
                        continueBank = true;
                        break;
                    case "3":
                        Console.WriteLine("1. Узнать общую сумму денег в банкоматах банка;");
                        Console.WriteLine("2. Снять деньги из банкомата;");
                        Console.WriteLine("3. Показать меню;");
                        Console.WriteLine("4. Выйти из программы.");
                        continueBank = true;
                        break;
                    case "4":
                        continueBank = false;
                        break;
                    default:
                        Console.WriteLine("Ошибка: неверный номер запроса.");
                        continueBank = true;
                        break;
                }
            
            }
            continueProgram = AskToContinue();
        }

        static void Task_1(Bank bank)
        {
            Console.WriteLine($"Общая сумма денег в банкоматах банка: {bank.GetTotalMoneyInATMs()} гривен");
        }

        static void Task_2(int atm, ATM atm1, ATM atm2)
        {
            bool continueAtm = true;
            Console.WriteLine("Укажите банкомат, с которого вы хотите снять наличные деньги:");
            while (continueAtm == true)
            {
                int numAtm = Convert.ToInt32(Console.ReadLine());

                if (numAtm <= atm)
                {
                    Console.WriteLine("Укажите сумму, которую вы хотите снять:");
                    int money = Convert.ToInt32(Console.ReadLine());

                    switch (numAtm)
                    {
                        case 1:
                            try
                            {
                                atm1.WithdrawMoney(money);
                                Console.WriteLine("Успешно снято " + money + " гривен из банкомата 1.");
                            }
                            catch (Exception ex)
                            {
                                Console.WriteLine(ex.Message);
                            }
                            continueAtm = false;
                            break;
                        case 2:
                            try
                            {
                                atm2.WithdrawMoney(money);
                                Console.WriteLine("Успешно снято " + money + " гривен из банкомата 2.");
                            }
                            catch (Exception ex)
                            {
                                Console.WriteLine(ex.Message);
                            }
                            continueAtm = false;
                            break;
                        default:
                            Console.WriteLine("Произошла ошибка");
                            continueAtm = false;
                            break;
                    }
                }
                else
                {
                    Console.WriteLine("Такого банкомата не существует.");
                    continueAtm = true;
                }
            }
           
        }

        static bool AskToContinue()
        {
            Console.WriteLine("Выйти из программы? (Y/N)");
            string response = Console.ReadLine().Trim().ToUpper();

            while (response != "Y" && response != "N")
            {
                Console.WriteLine("Ошибка: введите Y для продолжения или N для завершения.");
                response = Console.ReadLine().Trim().ToUpper();
            }

            return response == "N";
        }
    }
}
