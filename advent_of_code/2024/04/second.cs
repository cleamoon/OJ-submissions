using System;
using System.IO;

class Program
{
    static int ans = 0;

    static bool find_pos(char[,] array, int x, int y, int width, int height, char ch)
    {
        return x >= 0 && x < width && y >= 0 && y < height && array[x, y] == ch;
    }

    static void find(char[,] array, int x, int y, int width, int height)
    {
        bool b1, b2, b3, b4, b5;
        string[] ss = { "MS", "SM" };
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                b1 = find_pos(array, x, y, width, height, ss[i][0]);
                b2 = find_pos(array, x + 2, y, width, height, ss[j][1]);
                b3 = find_pos(array, x + 1, y + 1, width, height, 'A');
                b4 = find_pos(array, x, y + 2, width, height, ss[j][0]);
                b5 = find_pos(array, x + 2, y + 2, width, height, ss[i][1]);
                if (b1 && b2 && b3 && b4 && b5)
                {
                    ans += 1;
                }
            }
        }
    }
    static void Main()
    {
        string filePath = "input.txt";

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

            for (int i = 0; i < width - 2; i++)
            {
                for (int j = 0; j < height - 2; j++)
                {
                    find(array, i, j, width, height);
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
