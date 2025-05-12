# 두 수의 합

import sys

def input():
    return sys.stdin.readline().strip()

N = int(input())
arr = list(map(int, input().split()))
arr.sort()
X = int(input())

left = 0
right = len(arr) - 1
result = 0

while left < right:
    temp = arr[left] + arr[right]
    if  temp == X:
        result += 1
        left += 1
        right -= 1
    elif temp > X:
        right -= 1
    else:
        left += 1

print(result)