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

        // int width = 11;
        // int height = 7;
        int width = 101;
        int height = 103;
        int steps = 100;

        ulong[,] grid = new ulong[width, height];

        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                grid[i, j] = 0;
            }
        }

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
            int finalX = (px + steps * vx) % width;
            if (finalX < 0)
            {
                finalX += width;
            }
            int finalY = (py + steps * vy) % height;
            if (finalY < 0)
            {
                finalY += height;
            }
            grid[finalX, finalY]++;
        }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                Console.Write(grid[j, i]);
            }
            Console.WriteLine();
        }

        ulong numInFirstQuadrant = 0;
        ulong numInSecondQuadrant = 0;
        ulong numInThirdQuadrant = 0;
        ulong numInFourthQuadrant = 0;

        for (int i = 0; i < width / 2; i++)
        {
            for (int j = 0; j < height / 2; j++)
            {
                numInFirstQuadrant += grid[i, j];
            }
        }

        for (int i = width / 2 + 1; i < width; i++)
        {
            for (int j = 0; j < height / 2; j++)
            {
                numInSecondQuadrant += grid[i, j];
            }
        }

        for (int i = 0; i < width / 2; i++)
        {
            for (int j = height / 2 + 1; j < height; j++)
            {
                numInThirdQuadrant += grid[i, j];
            }
        }

        for (int i = width / 2 + 1; i < width; i++)
        {
            for (int j = height / 2 + 1; j < height; j++)
            {
                numInFourthQuadrant += grid[i, j];
            }
        }

        Console.WriteLine(numInFirstQuadrant * numInSecondQuadrant * numInThirdQuadrant * numInFourthQuadrant);
    }
}
