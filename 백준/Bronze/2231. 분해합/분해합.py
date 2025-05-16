# 분해합

import sys

def input():
    return sys.stdin.readline().strip()

num = int(input())
result = 0

for i in range(1, num + 1):
    cur_num = i
    temp = cur_num
    while cur_num > 0:
        temp += (cur_num % 10)
        cur_num //= 10
    if temp == num:
        result = i
        break

print(result)