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

        string line = lines[0];

        List<ulong> stones = line.Split(' ').Select(ulong.Parse).ToList();

        for (int i = 0; i < 25; i++)
        {
            List<ulong> temp = new List<ulong>();

            for (int j = 0; j < stones.Count; j++)
            {
                ulong stone = stones[j];
                if (stone == 0)
                {
                    temp.Add(1);
                }
                else if (stone.ToString().Length % 2 == 0)
                {
                    string digits = stone.ToString();
                    string firstHalf = digits.Substring(0, digits.Length / 2);
                    string secondHalf = digits.Substring(digits.Length / 2);
                    temp.Add(ulong.Parse(firstHalf));
                    temp.Add(ulong.Parse(secondHalf));
                }
                else
                {
                    temp.Add(stone * 2024);
                }
            }

            stones = temp;
        }

        Console.WriteLine(stones.Count);
    }
}
