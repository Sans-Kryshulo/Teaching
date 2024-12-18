using System;
using System.Collections.Generic;

namespace FirmApp
{
    public class Firm
    {
        public string Name { get; set; }
        public DateTime FoundedDate { get; set; }
        public string BusinessProfile { get; set; }
        public string Director { get; set; }
        public int EmployeeCount { get; set; }
        public string Address { get; set; }
        public List<Employee> Employees { get; set; } = new List<Employee>();

        public override string ToString()
        {
            return $"Name: {Name}, Founded: {FoundedDate.ToShortDateString()}, " +
                   $"Profile: {BusinessProfile}, Director: {Director}, " +
                   $"Employees: {EmployeeCount}, Address: {Address}";
        }
    }
}
