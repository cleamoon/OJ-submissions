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
        int last_val = -1;

        for (int i = 0; i < arr.Count; i++)
        {
            int size = arr[i];
            int digit = i % 2 == 0 ? curr : -1;
            for (int j = 0; j < size; j++)
            {
                disk.Add(digit);
                last_val = digit;
            }
            if (i % 2 == 0) curr += 1;
        }
        int last = disk.Count - 1;
        int first = 0;

        while (true)
        {
            if (last_val < 0)
            {
                break;
            }
            if (first >= last)
            {
                last_val -= 1;
                first = 0;
                continue;
            }
            if (disk[first] != -1)
            {
                first += 1;
                continue;
            }
            if (disk[last] != last_val)
            {
                last -= 1;
                continue;
            }
            int emp_len = 0;
            for (int i = first; i < disk.Count; i++)
            {
                if (disk[i] == -1)
                {
                    emp_len += 1;
                }
                else
                {
                    break;
                }
            }
            int file_len = 0;
            for (int i = last; i >= 0; i--)
            {
                if (disk[i] == last_val)
                {
                    file_len += 1;
                }
                else
                {
                    break;
                }
            }
            if (file_len > emp_len)
            {
                first += emp_len;
                continue;
            }
            else
            {
                for (int i = first; i < first + file_len; i++)
                {
                    disk[i] = disk[last];
                    disk[last] = -1;
                    last -= 1;
                }
                last_val -= 1;
                first = 0;
            }

        }

        if (false)
        {
            for (int i = 0; i < disk.Count; i++)
            {
                if (disk[i] == -1)
                {
                    Console.Write(".");
                }
                else
                {
                    Console.Write(disk[i]);
                }
            }
            Console.WriteLine();
        }

        ulong ans = 0;

        for (int i = 0; i < disk.Count; i++)
        {
            if (disk[i] != -1)
            {
                ans += ((ulong)i) * ((ulong)disk[i]);
            }
        }

        Console.WriteLine(ans);
    }

}
