# 덩치

import sys

def input():
    return sys.stdin.readline().strip()

N = int(input())
result = []
arr = list(list(map(int, input().split())) for _ in range(N))


for i in range(N):
    count = 0
    for j in range(N):
        if i == j:
            continue
        if arr[i][0] < arr[j][0] and arr[i][1] < arr[j][1]:
            count += 1
    result.append(count + 1)

print(*result)