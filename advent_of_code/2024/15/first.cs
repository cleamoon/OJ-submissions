using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void printGrid(List<List<char>> grid)
    {
        for (int i = 0; i < grid.Count; i++)
        {
            for (int j = 0; j < grid[i].Count; j++)
            {
                Console.Write(grid[i][j]);
            }
            Console.WriteLine();
        }
    }
    static void Main()
    {
        string filePath = "input.txt";
        string[] lines = File.ReadAllLines(filePath);
        int length = lines.Length;

        int width = lines[0].Length;
        int height = 0;
        int x = 0;
        int y = 0;

        List<List<char>> grid = new List<List<char>>();

        for (int i = 0; i < length; i++)
        {
            string line = lines[i];
            if (line.Length == 0)
            {
                break;
            }
            grid.Add(new List<char>());
            for (int j = 0; j < line.Length; j++)
            {
                grid[i].Add(line[j]);
                if (line[j] == '@')
                {
                    x = j;
                    y = i;
                }
            }
            height++;
        }

        List<char> steps = new List<char>();

        for (int i = grid.Count + 1; i < length; i++)
        {
            string line = lines[i];
            for (int j = 0; j < line.Length; j++)
            {
                steps.Add(line[j]);
            }
        }

        for (int i = 0; i < steps.Count; i++)
        {
            char step = steps[i];
            bool has_box = false;
            switch (step)
            {
                case '^':
                    for (int j = y - 1; j >= 0; j--)
                    {
                        if (grid[j][x] == '#')
                        {
                            break;
                        }
                        else if (grid[j][x] == 'O')
                        {
                            has_box = true;
                        }
                        else if (grid[j][x] == '.')
                        {
                            grid[y][x] = '.';
                            grid[y - 1][x] = '@';
                            y--;
                            if (has_box) grid[j][x] = 'O';
                            break;
                        }
                    }
                    break;
                case '>':
                    for (int j = x + 1; j < width; j++)
                    {
                        if (grid[y][j] == '#')
                        {
                            break;
                        }
                        else if (grid[y][j] == 'O')
                        {
                            has_box = true;
                        }
                        else if (grid[y][j] == '.')
                        {
                            grid[y][x] = '.';
                            grid[y][x + 1] = '@';
                            x++;
                            if (has_box) grid[y][j] = 'O';
                            break;
                        }
                    }
                    break;
                case 'v':
                    for (int j = y + 1; j < height; j++)
                    {
                        if (grid[j][x] == '#')
                        {
                            break;
                        }
                        else if (grid[j][x] == 'O')
                        {
                            has_box = true;
                        }
                        else if (grid[j][x] == '.')
                        {
                            grid[y][x] = '.';
                            grid[y + 1][x] = '@';
                            y++;
                            if (has_box) grid[j][x] = 'O';
                            break;
                        }
                    }
                    break;
                case '<':
                    for (int j = x - 1; j >= 0; j--)
                    {
                        if (grid[y][j] == '#')
                        {
                            break;
                        }
                        else if (grid[y][j] == 'O')
                        {
                            has_box = true;
                        }
                        else if (grid[y][j] == '.')
                        {
                            grid[y][x] = '.';
                            grid[y][x - 1] = '@';
                            x--;
                            if (has_box) grid[y][j] = 'O';
                            break;
                        }
                    }
                    break;
            }
        }

        int ans = 0;

        for (int i = 0; i < grid.Count; i++)
        {
            for (int j = 0; j < grid[i].Count; j++)
            {
                if (grid[i][j] == 'O')
                {
                    ans += i * 100 + j;
                }
            }
        }

        Console.WriteLine(ans);
    }
}
