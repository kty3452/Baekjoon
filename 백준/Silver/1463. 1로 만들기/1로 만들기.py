# 1로 만들기

import sys

def input():
    return sys.stdin.readline().strip()

X = int(input())
arr = [i for i in range(1000001)]

for i in range(1, 1000000):
    if arr[i + 1] > arr[i] + 1:
        arr[i + 1] = arr[i] + 1
    if i * 2 <= 1000000 and arr[i * 2] > arr[i] + 1:
        arr[i * 2] = arr[i] + 1
    if i * 3 <= 1000000 and arr[i * 3] > arr[i] + 1:
        arr[i * 3] = arr[i] + 1
print(arr[X] - 1)
 