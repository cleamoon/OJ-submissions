using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        string filePath = "input.txt";
        string[] lines = File.ReadAllLines(filePath);
        string str = lines[0];
        List<int> arr = str.ToCharArray().Select(x => x - '0').ToList();

        List<int> disk = new List<int>();
        int curr = 0;

        for (int i = 0; i < arr.Count; i++)
        {
            int size = arr[i];
            int digit = i % 2 == 0 ? curr : -1;
            for (int j = 0; j < size; j++)
            {
                disk.Add(digit);
            }
            if (i % 2 == 0) curr += 1;
        }
        int last = disk.Count - 1;
        int first = 0;

        while (first < last)
        {
            if (disk[first] != -1)
            {
                first += 1;
                continue;
            }
            if (disk[last] == -1)
            {
                last -= 1;
                continue;
            }
            disk[first] = disk[last];
            disk[last] = -1;
            first += 1;
            last -= 1;
        }

        ulong ans = 0;

        for (int i = 0; i < disk.Count; i++)
        {
            if (disk[i] != -1)
            {
                ans += ((ulong)i) * ((ulong)disk[i]);
            }
            else
            {
                break;
            }
        }

        Console.WriteLine(ans);
    }

}
