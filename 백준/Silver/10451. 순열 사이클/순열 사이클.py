# 순열 사이클
import sys

def user_input():
    return sys.stdin.readline().strip()


# def find(v, parent):
#     if v != parent[v]:
#         parent[v] = find(parent[v])
#     return parent[v]

# def union(a, b, parent):
#     a = find(a)
#     b = find(b)
#     if a != b:
#         root = min(a, b)
#         parent[a] = root
#         parent[b] = root

    
def dfs(cur_v, visited, graph):
    visited[cur_v] = 1
    next_v = graph[cur_v]
    if not visited[next_v]:
        dfs(next_v, visited, graph)


T = int(user_input())

for i in range(T):
    N = int(user_input())
    graph = [0] * (N + 1)
    graph[1:N+1] = list(map(int, user_input().split()))
    visited = [0] * (N + 1)
    cnt = 0
    # parent = [i for i in range(N + 1)]
    for cur_v in range(1, N + 1):
        if not visited[cur_v]:
            dfs(cur_v, visited, graph)
            cnt += 1
    print(cnt)

    
