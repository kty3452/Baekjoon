# 영화감독 숌

import sys

def input():
    return sys.stdin.readline().strip()
N = int(input())
cur_n = 1
num = 666
while cur_n < N:
    cnt = 0
    num += 1
    if "666" in str(num):
        cur_n += 1
print(num)