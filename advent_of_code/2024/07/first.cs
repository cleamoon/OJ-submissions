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

        ulong ans = 0;

        for (int i = 0; i < lines.Length; i++)
        {
            ulong target = ulong.Parse(lines[i].Split(':')[0]);
            List<ulong> nums = lines[i].Split(':')[1].Trim(' ').Split(' ').Select(ulong.Parse).ToList();
            List<ulong> generated = new List<ulong>();
            generated.Add(nums[0]);

            for (int j = 1; j < nums.Count; j++)
            {
                List<ulong> temp = new List<ulong>();

                for (int k = 0; k < generated.Count; k++)
                {
                    ulong sum = generated[k] + nums[j];
                    ulong prod = generated[k] * nums[j];

                    temp.Add(sum);
                    temp.Add(prod);
                }

                generated = temp;
            }

            if (generated.Contains(target))
            {
                ans += target;
            }
        }

        Console.WriteLine(ans);

    }

}
