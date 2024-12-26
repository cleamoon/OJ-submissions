using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;


class Program
{
    static void Main()
    {
        string filePath = "input.txt";

        int ans = 0;

        try
        {
            string[] lines = File.ReadAllLines(filePath);

            foreach (string line in lines)
            {
                string[] parts = line.Split(" ");
                List<int> numbers = parts.Select(int.Parse).ToList();
                if (numbers[0] == numbers[1]) continue;
                bool increase = numbers[0] < numbers[1];
                bool correct = true;
                for (int i = 1; i < numbers.Count; i++)
                {
                    if (increase && (numbers[i] - numbers[i - 1] > 3 || numbers[i] - numbers[i - 1] < 1))
                    {
                        correct = false;
                        break;
                    }
                    else if (!increase && (numbers[i - 1] - numbers[i] > 3 || numbers[i - 1] - numbers[i] < 1))
                    {
                        correct = false;
                        break;
                    }
                }
                if (correct) ans++;
            }
        }
        catch (Exception e)
        {
            Console.WriteLine(e.Message);
        }

        Console.WriteLine(ans);
    }
}