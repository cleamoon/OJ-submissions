
using System;
using System.IO;
using System.Collections.Generic;
using System.Text.RegularExpressions;


class Program
{

    static int comp(string input)
    {
        Console.WriteLine(input);
        string substring = input.Substring(4, input.Length - 5);
        Console.WriteLine(substring);
        string[] arr = substring.Split(',');
        return int.Parse(arr[0]) * int.Parse(arr[1]);
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
                string pattern = @"mul\(\d{1,3},\d{1,3}\)";

                Regex regex = new Regex(pattern);

                MatchCollection matches = regex.Matches(line);

                foreach (Match match in matches)
                {
                    ans += comp(match.Value);
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