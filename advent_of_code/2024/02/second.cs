using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;


class Program
{
    static bool isCorrect(List<int> numbers)
    {
        bool increase = false;

        if (numbers[0] < numbers[1])
        {
            increase = true;
        }
        else if (numbers[0] > numbers[1])
        {
            increase = false;
        }
        else
        {
            return false;
        }

        for (int i = 1; i < numbers.Count; i++)
        {
            if (increase && (numbers[i] - numbers[i - 1] > 3 || numbers[i] - numbers[i - 1] < 1))
            {
                return false;
            }
            else if (!increase && (numbers[i - 1] - numbers[i] > 3 || numbers[i - 1] - numbers[i] < 1))
            {
                return false;
            }
        }
        return true;
    }

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

                for (int i = 0; i < numbers.Count; i++)
                {
                    List<int> leftNumbers = new List<int>(numbers);
                    leftNumbers.RemoveAt(i);
                    if (isCorrect(leftNumbers))
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
        catch (Exception e)
        {
            Console.WriteLine(e.Message);
        }

        Console.WriteLine(ans);
    }
}