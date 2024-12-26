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
                List<(int, int, int)> perimeters = new List<(int, int, int)>();

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
                            perimeters.Add((sx, sy, 4));
                        }
                        else
                        {
                            spaces.Add((sx - 1, sy));
                        }
                    }
                    else
                    {
                        perimeters.Add((sx, sy, 4));
                    }

                    if (sx < width - 1)
                    {
                        if (map[sx + 1, sy] != ch)
                        {
                            perimeters.Add((sx, sy, 2));
                        }
                        else
                        {
                            spaces.Add((sx + 1, sy));
                        }
                    }
                    else
                    {
                        perimeters.Add((sx, sy, 2));
                    }

                    if (sy > 0)
                    {
                        if (map[sx, sy - 1] != ch)
                        {
                            perimeters.Add((sx, sy, 1));
                        }
                        else
                        {
                            spaces.Add((sx, sy - 1));
                        }
                    }
                    else
                    {
                        perimeters.Add((sx, sy, 1));
                    }

                    if (sy < height - 1)
                    {
                        if (map[sx, sy + 1] != ch)
                        {
                            perimeters.Add((sx, sy, 3));
                        }
                        else
                        {
                            spaces.Add((sx, sy + 1));
                        }
                    }
                    else
                    {
                        perimeters.Add((sx, sy, 3));
                    }
                }

                int perimeter = perimeters.Count;

                for (int m = 0; m < perimeters.Count; m++)
                {
                    for (int n = m + 1; n < perimeters.Count; n++)
                    {
                        (int, int, int) p1 = perimeters[m];
                        (int, int, int) p2 = perimeters[n];

                        if (p1.Item1 == p2.Item1 && p1.Item3 == p2.Item3 && Math.Abs(p1.Item2 - p2.Item2) == 1)
                        {
                            if (p1.Item3 == 2 || p1.Item3 == 4)
                            {
                                perimeter -= 1;
                            }
                        }
                        if (p1.Item2 == p2.Item2 && p1.Item3 == p2.Item3 && Math.Abs(p1.Item1 - p2.Item1) == 1)
                        {
                            if (p1.Item3 == 1 || p1.Item3 == 3)
                            {
                                perimeter -= 1;
                            }
                        }
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
