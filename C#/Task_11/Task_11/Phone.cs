using System;

namespace PhoneApp
{
    public class Phone
    {
        public string Name { get; set; }
        public string Manufacturer { get; set; }
        public decimal Price { get; set; }
        public DateTime ReleaseDate { get; set; }

        public override string ToString()
        {
            return $"{Name} ({Manufacturer}), Цена: {Price:C}, Дата выпуска: {ReleaseDate:d}";
        }
    }
}
