using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static int Infinite = 100000000;
    static void Main()
    {
        string filePath = "input.txt";
        string[] lines = File.ReadAllLines(filePath);
        int length = lines.Length;

        int width = lines[0].Length;
        int height = lines.Length;

        char[,] grid = new char[height, width];
        //        List<List<(int, int, int, int)>> costs = new List<List<(int, int, int, int)>>();
        (int, int, int, int)[,] costs = new (int, int, int, int)[height, width];
        Queue<(int, int)> queue = new Queue<(int, int)>();

        for (int i = 0; i < height; i++)
        {
            string line = lines[i];

            for (int j = 0; j < width; j++)
            {
                grid[j, i] = line[j];
                costs[j, i] = (Infinite, Infinite, Infinite, Infinite);

                if (line[j] == 'S')
                {
                    costs[j, i] = (1000, 0, 1000, 2000);
                    queue.Enqueue((j, i));
                }
            }
        }

        while (queue.Count > 0)
        {
            int x, y;
            (x, y) = queue.Dequeue();
            Console.WriteLine(x + " " + y + " " + grid[x, y]);
            if (x > 0 && grid[x - 1, y] != '#')
            {
                Console.WriteLine("left");
                int u2l = costs[x, y].Item1 + 1001;
                int r2l = costs[x, y].Item2 + 2001;
                int d2l = costs[x, y].Item3 + 1001;
                int l2l = costs[x, y].Item4 + 1;
                int min4 = Math.Min(u2l, Math.Min(r2l, Math.Min(d2l, l2l)));
                int min1 = Math.Min(min4 + 1000, costs[x - 1, y].Item1);
                int min2 = Math.Min(min4 + 2000, costs[x - 1, y].Item2);
                int min3 = Math.Min(min4 + 1000, costs[x - 1, y].Item3);
                if (min4 < costs[x - 1, y].Item4)
                {
                    costs[x - 1, y] = (min1, min2, min3, min4);
                    queue.Enqueue((x - 1, y));
                }
            }
            if (x < width - 1 && grid[x + 1, y] != '#')
            {
                Console.WriteLine("right");
                int u2r = costs[x, y].Item1 + 1001;
                int r2r = costs[x, y].Item2 + 1;
                int d2r = costs[x, y].Item3 + 1001;
                int l2r = costs[x, y].Item4 + 2001;
                int min2 = Math.Min(u2r, Math.Min(r2r, Math.Min(d2r, l2r)));
                int min1 = Math.Min(min2 + 1000, costs[x + 1, y].Item2);
                int min3 = Math.Min(min2 + 1000, costs[x + 1, y].Item3);
                int min4 = Math.Min(min2 + 2000, costs[x + 1, y].Item4);
                if (min2 < costs[x + 1, y].Item2)
                {
                    costs[x + 1, y] = (min1, min2, min3, min4);
                    queue.Enqueue((x + 1, y));
                }
            }
            if (y > 0 && grid[x, y - 1] != '#')
            {
                Console.WriteLine("up");
                int u2d = costs[x, y].Item1 + 2001;
                int r2d = costs[x, y].Item2 + 1001;
                int d2d = costs[x, y].Item3 + 1;
                int l2d = costs[x, y].Item4 + 1001;
                int min3 = Math.Min(u2d, Math.Min(r2d, Math.Min(d2d, l2d)));
                int min1 = Math.Min(min3 + 2000, costs[x, y - 1].Item1);
                int min2 = Math.Min(min3 + 1000, costs[x, y - 1].Item2);
                int min4 = Math.Min(min3 + 1000, costs[x, y - 1].Item4);
                if (min3 < costs[x, y - 1].Item3)
                {
                    costs[x, y - 1] = (min1, min2, min3, min4);
                    queue.Enqueue((x, y - 1));
                }
            }
            if (y < height - 1 && grid[x, y + 1] != '#')
            {
                Console.WriteLine("down");
                int u2r = costs[x, y].Item1 + 1;
                int r2r = costs[x, y].Item2 + 1001;
                int d2r = costs[x, y].Item3 + 2001;
                int l2r = costs[x, y].Item4 + 1001;
                int min1 = Math.Min(u2r, Math.Min(r2r, Math.Min(d2r, l2r)));
                int min2 = Math.Min(min1 + 1000, costs[x, y + 1].Item2);
                int min3 = Math.Min(min1 + 2000, costs[x, y + 1].Item3);
                int min4 = Math.Min(min1 + 1000, costs[x, y + 1].Item4);
                if (min4 < costs[x, y + 1].Item1)
                {
                    costs[x, y + 1] = (min1, min2, min3, min4);
                    queue.Enqueue((x, y + 1));
                }
            }
            Console.WriteLine(queue.Count);
        }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                Console.WriteLine(costs[j, i]);
                if (grid[j, i] == 'E')
                {
                    (int, int, int, int) cost = costs[j, i];
                    int min = Math.Min(cost.Item1, Math.Min(cost.Item2, Math.Min(cost.Item3, cost.Item4)));
                    Console.WriteLine(min);
                    return;
                }
            }
            Console.WriteLine();
        }

        Console.WriteLine();

    }
}
