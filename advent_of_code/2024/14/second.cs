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
        int length = lines.Length;

        int width = 101;
        int height = 103;

        int[,] grid = new int[width, height];

        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                grid[i, j] = 0;
            }
        }

        int[] xs = new int[length];
        int[] ys = new int[length];
        int[] vxs = new int[length];
        int[] vys = new int[length];

        for (int i = 0; i < length; i++)
        {
            string line = lines[i];
            string[] parts = line.Split(' ');
            int px, py, vx, vy;
            int[] parr = parts[0].Substring(2, parts[0].Length - 2).Split(',').Select(int.Parse).ToArray();
            int[] varr = parts[1].Substring(2, parts[1].Length - 2).Split(',').Select(int.Parse).ToArray();
            px = parr[0];
            py = parr[1];
            vx = varr[0];
            vy = varr[1];
            xs[i] = px;
            ys[i] = py;
            vxs[i] = vx;
            vys[i] = vy;
            grid[px, py]++;
        }

        // F*****************************ck
        for (int i = 0; i < 10000; i++)
        {
            Console.WriteLine(i + 1);

            for (int j = 0; j < length; j++)
            {
                grid[xs[j], ys[j]]--;
                xs[j] = (xs[j] + vxs[j]) % width;
                ys[j] = (ys[j] + vys[j]) % height;
                if (xs[j] < 0) xs[j] += width;
                if (ys[j] < 0) ys[j] += height;
                grid[xs[j], ys[j]]++;
            }


            for (int p = 0; p < height; p++)
            {
                for (int q = 0; q < width; q++)
                {
                    if (grid[q, p] > 0)
                    {
                        Console.Write("#");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
}
