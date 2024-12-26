
using System;
using System.IO;
using System.Collections.Generic;
using System.Text.RegularExpressions;


class Program
{

    static int comp(string input)
    {
        string substring = input.Substring(4, input.Length - 5);
        string[] arr = substring.Split(',');
        return int.Parse(arr[0]) * int.Parse(arr[1]);
    }
    static void Main()
    {
        string filePath = "input.txt";
        int ans = 0;
        bool running = true;

        try
        {
            string[] lines = File.ReadAllLines(filePath);

            foreach (string line in lines)
            {
                string pattern = @"(mul\(\d{1,3},\d{1,3}\)|do\(\)|don't\(\))";

                Regex regex = new Regex(pattern);

                MatchCollection matches = regex.Matches(line);

                foreach (Match match in matches)
                {
                    if (match.Value == "do()")
                    {
                        running = true;
                    }
                    else if (match.Value == "don't()")
                    {
                        running = false;
                    }
                    else if (match.Value.StartsWith("mul(") && running)
                    {
                        ans += comp(match.Value);
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