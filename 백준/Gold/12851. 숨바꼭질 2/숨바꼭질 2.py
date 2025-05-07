# 숨바꼭질2

import sys
from collections import deque

area = [0] * 100001
N, K = map(int, sys.stdin.readline().strip().split())
way_count = 0

area[N] = 1
queue = deque([N])

while queue:
    cv = queue.popleft()
    for nv in (cv - 1, cv + 1, cv * 2):
        if 100000 >= nv >= 0 and (not area[nv] or area[nv] == area[cv] + 1):
            
            queue.append(nv)
            if not area[nv]:
                area[nv] = area[cv] + 1
            if nv == K:
                way_count += 1


if way_count == 0:
    way_count = 1

print(area[K] - 1)
print(way_count)