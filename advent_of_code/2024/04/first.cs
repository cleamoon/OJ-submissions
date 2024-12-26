using System;
using System.IO;

class Program
{
    static int ans = 0;

    static void find(char[,] array, int x, int y, int width, int height, string str, int pos, int dir = 0)
    {
        int i, j;
        switch (dir)
        {
            case 0:
                i = x - 1;
                j = y;
                break;
            case 1:
                i = x;
                j = y + 1;
                break;
            case 2:
                i = x + 1;
                j = y;
                break;
            case 3:
                i = x;
                j = y - 1;
                break;
            case 4:
                i = x - 1;
                j = y - 1;
                break;
            case 5:
                i = x - 1;
                j = y + 1;
                break;
            case 6:
                i = x + 1;
                j = y + 1;
                break;
            case 7:
                i = x + 1;
                j = y - 1;
                break;
            default:
                i = x;
                j = y;
                break;
        }

        if (i >= 0 && i < width && j >= 0 && j < height && (i != x || j != y) && array[i, j] == str[pos])
        {
            Console.WriteLine($"{i} {j} {str[pos]}");
            if (pos == str.Length - 1)
            {
                ans += 1;
                return;
            }
            else
            {
                find(array, i, j, width, height, str, pos + 1, dir);
            }
        }
    }
    static void Main()
    {
        string filePath = "input.txt";
        string str = "XMAS";

        try
        {
            string[] lines = File.ReadAllLines(filePath);

            int width = lines.Length;
            int height = lines[0].Length;

            char[,] array = new char[width, height];

            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < height; j++)
                {
                    array[i, j] = lines[i][j];
                }
            }

            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < height; j++)
                {
                    if (array[i, j] == str[0])
                    {
                        for (int k = 0; k < 8; k++)
                        {
                            find(array, i, j, width, height, str, 1, k);
                        }
                    }
                }
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"An error occurred: {ex.Message}");
        }

        Console.WriteLine(ans);
    }
}
