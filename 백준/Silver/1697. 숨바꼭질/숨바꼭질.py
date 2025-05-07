# 숨바꼭질

import sys
from collections import deque

area = [0] * 100001
N, K = map(int, sys.stdin.readline().strip().split())

area[N] = 1
queue = deque([N])

while queue:
    cv = queue.popleft()
    for nv in (cv - 1, cv + 1, cv * 2):
        if 100000 >= nv >= 0 and not area[nv]:
            queue.append(nv)
            area[nv] = area[cv] + 1

print(area[K] - 1)