namespace CafeQueueApp
{
    public class Customer
    {
        public string Name { get; private set; }
        public bool HasReservation { get; private set; }
        public string ReservationTime { get; private set; }

        public Customer(string name, bool hasReservation, string reservationTime = null)
        {
            Name = name;
            HasReservation = hasReservation;
            ReservationTime = reservationTime;
        }

        public override string ToString()
        {
            if (HasReservation)
            {
                return $"{Name} (с резервом на {ReservationTime})";
            }
            else
            {
                return Name;
            }
        }
    }
}

