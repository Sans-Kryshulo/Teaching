using System;
using System.Threading;

namespace TamagotchiApp
{
    public class Tamagotchi
    {
        private Random random;
        private string[] requests = { "покормить", "погулять", "уложить спать", "полечить", "поиграть" };
        private string lastRequest;
        private int requestFails;
        private bool isSick;
        private bool isAlive;

        public event Action<string> OnRequest;
        public event Action<string> OnStatusChange;
        public event Action OnDeath;

        public Tamagotchi()
        {
            random = new Random();
            requestFails = 0;
            isSick = false;
            isAlive = true;
        }

        public void StartLifeCycle()
        {
            Console.Clear();
            Console.WriteLine("Ваш Тамагочи начал свой жизненный цикл!");

            while (isAlive)
            {
                GenerateRequest();

                if (requestFails >= 3)
                {
                    if (isSick)
                    {
                        OnStatusChange?.Invoke("Тамагочи заболел и просит его полечить. Если не помочь, он умрет.");
                    }
                    else
                    {
                        BecomeSick();
                    }
                }

                Thread.Sleep(2000);
            }
        }

        private void GenerateRequest()
        {
            string request;

            do
            {
                request = requests[random.Next(requests.Length)];
            } while (request == lastRequest);

            lastRequest = request;

            OnRequest?.Invoke(request);

            Thread.Sleep(5000); 

            if (requestFails >= 3)
            {
                Die();
            }
        }

        public void FulfillRequest(string request)
        {
            if (request == lastRequest && isAlive)
            {
                requestFails = 0;
                isSick = false;
                OnStatusChange?.Invoke($"Запрос \"{request}\" выполнен.");
            }
            else
            {
                OnStatusChange?.Invoke("Неправильный запрос.");
                requestFails++;
            }
        }

        private void BecomeSick()
        {
            isSick = true;
            OnStatusChange?.Invoke("Тамагочи заболел. Нужно его полечить.");
        }

        private void Die()
        {
            isAlive = false;
            OnDeath?.Invoke();
        }
    }
}
