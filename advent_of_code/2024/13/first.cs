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

        string s1 = "Button A: ";
        string s2 = "Prize: ";
        string ss = "X=";

        for (int i = 0; i <= lines.Length / 4; i++)
        {
            string[] ba = lines[i * 4].Substring(s1.Length).Split(", ");
            string[] bb = lines[i * 4 + 1].Substring(s1.Length).Split(", ");
            ulong bax = ulong.Parse(ba[0].Substring(ss.Length));
            ulong bay = ulong.Parse(ba[1].Substring(ss.Length));
            ulong bbx = ulong.Parse(bb[0].Substring(ss.Length));
            ulong bby = ulong.Parse(bb[1].Substring(ss.Length));
            string[] p = lines[i * 4 + 2].Substring(s2.Length).Split(", ");
            ulong px = ulong.Parse(p[0].Substring(ss.Length));
            ulong py = ulong.Parse(p[1].Substring(ss.Length));

            ulong min = ulong.MaxValue;
            bool found = false;

            for (ulong a = 0; a <= 100; a++)
            {
                if (bax * a > px || bay * a > py)
                {
                    break;
                }

                ulong rx = px - bax * a;
                ulong ry = py - bay * a;

                if (rx % bbx == 0 && ry % bby == 0)
                {
                    ulong b = rx / bbx;
                    if (b > 100) continue;
                    if (b * bby == ry)
                    {
                        min = Math.Min(min, 3 * a + b);
                        found = true;
                    }
                }
            }

            if (found)
            {
                ans += min;
            }
        }

        Console.WriteLine(ans);
    }
}
