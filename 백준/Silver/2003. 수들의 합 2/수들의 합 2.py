# 수들의 합 2

import sys

def input():
    return sys.stdin.readline().strip()

N, M = map(int, input().split())

arr = list(map(int, input().split()))
result = 0
left = 0
right = 0
hap = arr[0]

while right < N:
    if hap == M:
        result += 1
    if hap <= M:
        right += 1
        if right < N:
            hap += arr[right]
    else:
        hap -= arr[left]
        left += 1


print(result)
