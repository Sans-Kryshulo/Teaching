using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PalindromeApp
{
    public static class PalindromeChecker
    {
        public static bool IsPalindrome(int number)
        {
            string numStr = number.ToString();
            int length = numStr.Length;

            for (int i = 0; i < length / 2; i++)
            {
                if (numStr[i] != numStr[length - 1 - i])
                {
                    return false;
                }
            }
            return true;
        }
    }
}
