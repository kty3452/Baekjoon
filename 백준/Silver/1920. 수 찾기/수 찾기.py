# 수 찾기

import sys

N = int(sys.stdin.readline().strip())

arr = set(map(int, sys.stdin.readline().strip().split()))

M = int(sys.stdin.readline().strip())

for x in list(map(int, sys.stdin.readline().strip().split())):
    print(1 if x in arr else 0)
