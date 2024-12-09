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
        int ans = 0;
        List<int[]> list = new List<int[]>();

        int n = 0;
        for (; n < lines.Length; n++)
        {
            if (lines[n] == "")
            {
                break;
            }

            string[] parts = lines[n].Split('|');

            int[] arr = new int[2];

            arr[0] = int.Parse(parts[0]);
            arr[1] = int.Parse(parts[1]);

            list.Add(arr);
        }

        n++;

        for (int i = n; i < lines.Length; i++)
        {
            bool found = false;
            int[] arr = lines[i].Split(',').Select(int.Parse).ToArray();
            for (int p = 0; p < list.Count; p++)
            {
                int u = list[p][0];
                int v = list[p][1];

                int pos_u = Array.IndexOf(arr, u);
                int pos_v = Array.IndexOf(arr, v);

                if (pos_u != -1 && pos_v != -1 && pos_u > pos_v)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                Console.WriteLine(lines[i]);
                int middle = arr[arr.Length / 2];
                ans += middle;
            }
        }

        Console.WriteLine(ans);
    }

}
