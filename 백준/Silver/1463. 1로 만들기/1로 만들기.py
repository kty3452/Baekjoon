# 1로 만들기

import sys

def input():
    return sys.stdin.readline().strip()

X = int(input())
arr = [float("inf")] * (X + 1)
arr[1] = 0

for i in range(1, X):
    if arr[i + 1] > arr[i] + 1:
        arr[i + 1] = arr[i] + 1
    if i * 2 <= X and arr[i * 2] > arr[i] + 1:
        arr[i * 2] = arr[i] + 1
    if i * 3 <= X and arr[i * 3] > arr[i] + 1:
        arr[i * 3] = arr[i] + 1
print(arr[X])
 