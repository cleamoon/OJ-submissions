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

        long ans = 0;

        string s1 = "Button A: ";
        string s2 = "Prize: ";
        string ss = "X=";

        long extra = 10000000000000;

        for (int i = 0; i <= lines.Length / 4; i++)
        {
            string[] ba = lines[i * 4].Substring(s1.Length).Split(", ");
            string[] bb = lines[i * 4 + 1].Substring(s1.Length).Split(", ");
            long bax = long.Parse(ba[0].Substring(ss.Length));
            long bay = long.Parse(ba[1].Substring(ss.Length));
            long bbx = long.Parse(bb[0].Substring(ss.Length));
            long bby = long.Parse(bb[1].Substring(ss.Length));
            string[] p = lines[i * 4 + 2].Substring(s2.Length).Split(", ");
            long px = long.Parse(p[0].Substring(ss.Length)) + extra;
            long py = long.Parse(p[1].Substring(ss.Length)) + extra;

            long b = (py * bax - bay * px) / (bby * bax - bbx * bay);
            long a = (px - b * bbx) / bax;

            if (a >= 0 && b >= 0 && a * bax + b * bbx == px && a * bay + b * bby == py)
            {
                ans += 3 * a + b;
            }
        }
        Console.WriteLine(ans);
    }
}
