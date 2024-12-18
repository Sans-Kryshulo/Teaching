namespace FirmApp
{
    public class Employee
    {
        public string FullName { get; set; }
        public string Position { get; set; }
        public string Phone { get; set; }
        public string Email { get; set; }
        public decimal Salary { get; set; }

        public override string ToString()
        {
            return $"Name: {FullName}, Position: {Position}, Phone: {Phone}, Email: {Email}, Salary: {Salary:C}";
        }
    }
}
