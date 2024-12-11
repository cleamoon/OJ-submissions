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
        int[,] map = new int[width, height];

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                map[x, y] = lines[y][x] - '0';
            }
        }

        int ans = 0;


        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                if (map[x, y] == 0)
                {
                    Queue<(int, int, int)> q = new Queue<(int, int, int)>(new[] { (x, y, 0) });

                    while (q.Count > 0)
                    {
                        (int, int, int) pos = q.Dequeue();
                        int xx = pos.Item1;
                        int yy = pos.Item2;
                        int curr = pos.Item3;

                        if (xx < 0 || xx >= width || yy < 0 || yy >= height || curr > 9)
                        {
                            continue;
                        }

                        if (map[xx, yy] == curr)
                        {
                            if (curr == 9)
                            {
                                ans += 1;
                                continue;
                            }

                            q.Enqueue((xx + 1, yy, curr + 1));
                            q.Enqueue((xx - 1, yy, curr + 1));
                            q.Enqueue((xx, yy + 1, curr + 1));
                            q.Enqueue((xx, yy - 1, curr + 1));
                        }
                    }

                }
            }
        }

        Console.WriteLine(ans);
    }

}
