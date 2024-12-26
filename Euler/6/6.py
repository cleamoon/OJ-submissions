#!/bin/python3

import sys


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print((6*n*n*n*n + 4*n*n*n - 6*n*n - 4*n)//24)