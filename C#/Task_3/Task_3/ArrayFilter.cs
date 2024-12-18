using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArrayFilterApp
{
    public static class ArrayFilter
    {
        public static int[] FilterArray(int[] originalArray, int[] filterArray)
        {
            HashSet<int> filterSet = new HashSet<int>(filterArray);
            List<int> result = new List<int>();

            foreach (int item in originalArray)
            {
                if (!filterSet.Contains(item))
                {
                    result.Add(item);
                }
            }

            return result.ToArray();
        }
    }
}
