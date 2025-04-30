from collections import deque
import sys

temp = sys.stdin.readline().strip().split(' ')
N = int(temp[0])
M = int(temp[1])
visited = [0] * (N + 1)
edges = [0] * M
count = 0

for i in range(M):
    edge = sys.stdin.readline().strip().split(' ')
    edges[i] = [int(edge[0]), int(edge[1])]

adj = [[] for _ in range(N + 1)]
for edge1, edge2 in edges:
    adj[edge1].append(edge2)
    adj[edge2].append(edge1)

    
for i in range(1, N + 1):
    if not visited[i]:
        queue = deque()
        queue.append(i)
        visited[i] = 1
        while len(queue) > 0:
            V = queue.popleft()
            for next_node in adj[V]:
                if  not visited[next_node]:
                    visited[next_node] = 1
                    queue.append(next_node)

        count += 1
print(count)


