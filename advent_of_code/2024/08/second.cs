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

        char[,] grid = new char[width, height];
        bool[,] antinode_grid = new bool[width, height];

        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                grid[i, j] = lines[j][i];
                antinode_grid[i, j] = false;
            }
        }

        Dictionary<char, List<int[]>> antenna = new Dictionary<char, List<int[]>>();

        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                if (grid[i, j] == '.')
                {
                    continue;
                }
                if (antenna.ContainsKey(grid[i, j]))
                {
                    antenna[grid[i, j]].Add(new int[] { i, j });
                }
                else
                {
                    antenna[grid[i, j]] = new List<int[]> { new int[] { i, j } };
                }
            }
        }

        foreach (var item in antenna)
        {
            List<int[]> array = item.Value;
            if (array.Count == 1)
            {
                continue;
            }

            for (int i = 0; i < array.Count; i++)
            {
                for (int j = i + 1; j < array.Count; j++)
                {
                    int[] first = array[i];
                    int[] second = array[j];

                    int x1 = first[0], y1 = first[1], x2 = second[0], y2 = second[1];

                    antinode_grid[x1, y1] = true;
                    antinode_grid[x2, y2] = true;

                    int dx = x2 - x1;
                    int dy = y2 - y1;

                    for (int k = 1; ; k++)
                    {
                        int xp = x1 - k * dx;
                        int yp = y1 - k * dy;

                        if (xp < 0 || xp >= width || yp < 0 || yp >= height)
                        {
                            break;
                        }

                        antinode_grid[xp, yp] = true;
                    }

                    for (int k = 1; ; k++)
                    {
                        int xq = x2 + k * dx;
                        int yq = y2 + k * dy;

                        if (xq < 0 || xq >= width || yq < 0 || yq >= height)
                        {
                            break;
                        }

                        antinode_grid[xq, yq] = true;
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (antinode_grid[j, i])
                {
                    ans++;
                }
            }
        }

        Console.WriteLine(ans);
    }

}
