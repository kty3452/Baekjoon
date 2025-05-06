# 촌수 계산

import sys
from collections import deque

N = int(sys.stdin.readline().strip())
start, goal = map(int, sys.stdin.readline().strip().split())

visited = [0] * (N + 1)
adj = [[] for _ in range(N + 1)]

M = int(sys.stdin.readline().strip())

for i in range(M):
    i, j = map(int, sys.stdin.readline().strip().split())
    adj[i].append(j)
    adj[j].append(i)

queue = deque([start])
while queue:
    cv = queue.popleft()
    for nv in adj[cv]:
        if not visited[nv]:
            queue.append(nv)
            visited[nv] = visited[cv] + 1

if visited[goal] == 0:
    visited[goal] = -1

print(visited[goal])