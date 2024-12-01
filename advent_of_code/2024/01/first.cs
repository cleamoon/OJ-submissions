using System;
using System.IO;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        string filePath = "input.txt";
        int ans = 0;
        List<int> l1 = new List<int>();
        List<int> l2 = new List<int>();

        try
        {
            // Read all lines from the file into a string array
            string[] lines = File.ReadAllLines(filePath);

            // Print each line
            foreach (string line in lines)
            {
                int a, b;
                string[] parts = line.Split("   ");
                a = int.Parse(parts[0]);
                l1.Add(a);
                b = int.Parse(parts[1]);
                l2.Add(b);
            }
            l1.Sort();
            l2.Sort();
            for (int i = 0; i < l1.Count; i++)
            {
                ans += Math.Abs(l1[i] - l2[i]);
            }
        }
        catch (Exception e)
        {
            Console.WriteLine("The file could not be read:");
            Console.WriteLine(e.Message);
        }
        Console.WriteLine(ans);
    }
}