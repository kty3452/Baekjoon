from collections import deque

temp = input().split(' ')
N = int(temp[0])
M = int(temp[1])
V = int(temp[2])

visited_dfs = [0] * (N + 1)
visited_bfs = [0] * (N + 1)
result_dfs = []
result_bfs = []
stack = [V]
queue = [V]
edges = [0] * M

for i in range(M):
    edge = input()
    edge = edge.split(" ")
    edges[i] = [int(edge[0]), int(edge[1])]

adj = [[] for _ in range(N + 1)]
for a, b in edges:
    adj[a].append(b)
    adj[b].append(a)
for i in range(1, N + 1):
    adj[i].sort()

while len(stack) > 0:
    temp_V = stack.pop()
    if(not visited_dfs[temp_V]):
        result_dfs.append(temp_V)
        visited_dfs[temp_V] = 1
        for i in reversed(adj[temp_V]):
            if  visited_dfs[i] == 0:
                stack.append(i)

for i in result_dfs:
    print(i, end=' ')
print()

visited_bfs[V] = 1
result_bfs.append(V)

while len(queue) > 0:
    temp_V = queue.pop(0)
    for i in adj[temp_V]:
        if  visited_bfs[i] == 0:
            result_bfs.append(i)
            visited_bfs[i] = 1
            queue.append(i)


for i in result_bfs:
    print(i, end=' ')

