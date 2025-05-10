# 공유기 설치

import sys

def input():
    return sys.stdin.readline().strip()

N, C = map(int, input().split())

houses = list(int(input()) for _ in range(N))
houses.sort()

dists = list((houses[i + 1] - houses[i]) for i in range(N - 1))

max_dist = sum(dists)
min_dist = min(dists)
result = 0

while min_dist <= max_dist:
    mid_dist = (min_dist + max_dist) // 2
    count = 1
    temp = 0
    for dist in dists:
        temp += dist
        if temp >= mid_dist:
            count += 1
            temp = 0
    if count >= C:
        result = mid_dist
        min_dist = mid_dist + 1

    else:
        max_dist = mid_dist - 1

print(result)