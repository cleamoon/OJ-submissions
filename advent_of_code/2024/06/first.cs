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
        int width = lines[0].Length;
        int height = lines.Length;

        int x = 0;
        int y = 0;
        int dir = 0;

        int[,] grid = new int[width, height];

        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                grid[i, j] = lines[j][i];
                if (grid[i, j] == '^')
                {
                    x = i;
                    y = j;
                }
            }
        }

        int ans = 0;

        while (true)
        {
            if (y < 0 || y > height || x < 0 || x > width)
            {
                break;
            }

            if (grid[x, y] != 'X')
            {
                ans++;
                grid[x, y] = 'X';
            }

            switch (dir)
            {
                case 0:
                    if (y - 1 < 0 || grid[x, y - 1] != '#')
                    {
                        y--;
                    }
                    else
                    {
                        dir = 1;
                    }
                    break;
                case 1:
                    if (x + 1 >= width || grid[x + 1, y] != '#')
                    {
                        x++;
                    }
                    else
                    {
                        dir = 2;
                    }
                    break;
                case 2:
                    if (y + 1 >= height || grid[x, y + 1] != '#')
                    {
                        y++;
                    }
                    else
                    {
                        dir = 3;
                    }
                    break;
                case 3:
                    if (x - 1 < 0 || grid[x - 1, y] != '#')
                    {
                        x--;
                    }
                    else
                    {
                        dir = 0;
                    }
                    break;
            }
        }

        Console.WriteLine(ans);
    }

}
