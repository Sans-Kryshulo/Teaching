using System;
using System.Collections.Generic;

namespace CafeQueueApp
{
    public class CafeQueueManager
    {
        private Queue<Customer> queue;
        private List<Customer> reservedCustomers;

        public CafeQueueManager()
        {
            queue = new Queue<Customer>();
            reservedCustomers = new List<Customer>();
        }

        public void EnqueueCustomer(Customer customer)
        {
            if (customer.HasReservation)
            {
                reservedCustomers.Add(customer);
                Console.WriteLine($"{customer.Name} добавлен в список резервов.");
            }
            else
            {
                queue.Enqueue(customer);
                Console.WriteLine($"{customer.Name} добавлен в очередь.");
            }
        }

        public void ServeNextCustomer()
        {
            if (reservedCustomers.Count > 0)
            {
                var customer = reservedCustomers[0];
                reservedCustomers.RemoveAt(0);
                Console.WriteLine($"{customer.Name} с резервом занял столик.");
            }
            else if (queue.Count > 0)
            {
                var customer = queue.Dequeue();
                Console.WriteLine($"{customer.Name} занял столик.");
            }
            else
            {
                Console.WriteLine("В очереди нет клиентов.");
            }
        }

        public void DisplayQueue()
        {
            Console.WriteLine("Текущая очередь:");
            foreach (var customer in queue)
            {
                Console.WriteLine(customer.Name);
            }
        }

        public void DisplayReservations()
        {
            Console.WriteLine("Клиенты с резервами:");
            foreach (var customer in reservedCustomers)
            {
                Console.WriteLine($"{customer.Name} на {customer.ReservationTime}");
            }
        }
    }
}
