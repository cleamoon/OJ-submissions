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

        char[,] map = new char[width, height];
        bool[,] visited = new bool[width, height];

        int ans = 0;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                map[x, y] = lines[y][x];
            }
        }

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                if (visited[x, y])
                {
                    continue;
                }

                char ch = map[x, y];

                List<(int, int)> spaces = new List<(int, int)> { (x, y) };

                int area = 0;
                int perimeter = 0;

                while (spaces.Count > 0)
                {
                    (int, int) space = spaces[0];
                    spaces.RemoveAt(0);

                    int sx = space.Item1;
                    int sy = space.Item2;

                    if (visited[sx, sy])
                    {
                        continue;
                    }

                    visited[sx, sy] = true;

                    if (map[sx, sy] != ch)
                    {
                        continue;
                    }

                    area++;

                    if (sx > 0)
                    {
                        if (map[sx - 1, sy] != ch)
                        {
                            perimeter++;
                        }
                        else
                        {
                            spaces.Add((sx - 1, sy));
                        }
                    }
                    else
                    {
                        perimeter++;
                    }

                    if (sx < width - 1)
                    {
                        if (map[sx + 1, sy] != ch)
                        {
                            perimeter++;
                        }
                        else
                        {
                            spaces.Add((sx + 1, sy));
                        }
                    }
                    else
                    {
                        perimeter++;
                    }

                    if (sy > 0)
                    {
                        if (map[sx, sy - 1] != ch)
                        {
                            perimeter++;
                        }
                        else
                        {
                            spaces.Add((sx, sy - 1));
                        }
                    }
                    else
                    {
                        perimeter++;
                    }

                    if (sy < height - 1)
                    {
                        if (map[sx, sy + 1] != ch)
                        {
                            perimeter++;
                        }
                        else
                        {
                            spaces.Add((sx, sy + 1));
                        }
                    }
                    else
                    {
                        perimeter++;
                    }
                }

                if (area > 0)
                {
                    ans += area * perimeter;
                }
            }
        }

        Console.WriteLine(ans);
    }
}
