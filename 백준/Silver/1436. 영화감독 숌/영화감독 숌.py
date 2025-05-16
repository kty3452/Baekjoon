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
    temp = num
    while temp > 0:
        if temp % 10 == 6:
            cnt += 1
            if cnt >= 3:
                cur_n += 1
                break
        else:
            cnt = 0
        temp //= 10
print(num)