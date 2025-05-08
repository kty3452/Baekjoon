# 숫자 카드 2

import sys

N = int(sys.stdin.readline().strip())
number_count = [0] * 20000001

for i in list(map(int, sys.stdin.readline().strip().split())):
    number_count[i + 10000000] += 1

M = int(sys.stdin.readline().strip())

for i in list(map(int, sys.stdin.readline().strip().split())):
    print(number_count[i + 10000000], end=" ")
