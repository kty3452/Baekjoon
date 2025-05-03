# 바이러스

from collections import deque
import sys

N = int(sys.stdin.readline().strip())
M = int(sys.stdin.readline().strip())

visited = [0] * (N + 1)

adj = [[] for _ in range(N + 1)]
for i in range(M):
    a, b = map(int, sys.stdin.readline().strip().split())
    adj[a].append(b)
    adj[b].append(a)

visited[1] = 1
queue = deque([1])
result = 0
while queue:
    cv = queue.popleft()
    for nv in adj[cv]:
        if visited[nv] == 0:
            visited[nv] = 1
            queue.append(nv)
            result += 1

print(result)
