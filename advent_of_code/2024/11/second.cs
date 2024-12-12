using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static List<ulong> process(List<ulong> stone_in)
    {
        List<ulong> stone_out = new List<ulong>();

        foreach (ulong stone in stone_in)
        {
            if (stone == 0)
            {
                stone_out.Add(1);
            }
            else if (stone.ToString().Length % 2 == 0)
            {
                string digits = stone.ToString();
                string firstHalf = digits.Substring(0, digits.Length / 2);
                string secondHalf = digits.Substring(digits.Length / 2);
                stone_out.Add(ulong.Parse(firstHalf));
                stone_out.Add(ulong.Parse(secondHalf));
            }
            else
            {
                stone_out.Add(stone * 2024);
            }
        }

        return stone_out;
    }

    static void Main()
    {
        string filePath = "input.txt";

        string[] lines = File.ReadAllLines(filePath);
        string line = lines[0];

        List<ulong> stones = line.Split(' ').Select(ulong.Parse).ToList();
        Dictionary<ulong, Dictionary<int, ulong>> stoneCount = new Dictionary<ulong, Dictionary<int, ulong>>();

        for (ulong i = 0; i < 10; i++)
        {
            stoneCount.Add(i, new Dictionary<int, ulong>());
        }

        for (ulong i = 0; i < 10; i++)
        {
            List<ulong> temp = new List<ulong> { i };
            for (int s = 0; s < 40; s++)
            {
                temp = process(temp);
                stoneCount[i].Add(s + 1, (ulong)temp.Count);
            }
        }

        for (int i = 0; i < 35; i++)
        {
            stones = process(stones);
        }

        ulong ans = 0;

        for (int i = 0; i < 40; i++)
        {
            foreach (ulong stone in stones)
            {
                if (stone < 10)
                {
                    ans += stoneCount[stone][40 - i];
                }
            }
            stones.RemoveAll(stone => stone < 10);

            stones = process(stones);
        }

        Console.WriteLine(((ulong)stones.Count) + ans);
    }
}
