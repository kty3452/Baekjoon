# 이분 그래프
# 이분 그래프란 그래프의 모든 노드를 두 집합으로 나눴을 때,
# 같은 집합 내에서는 연결 되어 있지 않고,
# 다른 집합에 있는 노드와만 연결되어 있는 그래프를 의미함
# 구현 할 때에는 인접한 노드들의 색이 없다면 다른 색으로 칠하고,
# 색이 있다면 비교하여 같은지 검사함.
# 만약 같다면 이분 그래프가 아님.

import sys
from collections import deque

K = int(sys.stdin.readline().strip())

for i in range(K):
    V, E = map(int, sys.stdin.readline().strip().split())
    
    # -1 -> 방문 안함, 0, 1 -> 색깔
    colors = [-1] * (V + 1)
    is_bipartite_graph = True
    
    adj = [[] for _ in range(V + 1)]
    for j in range(E):
        a, b = map(int, sys.stdin.readline().strip().split())
        adj[a].append(b)
        adj[b].append(a)

    for j in range(1, V + 1):
        if colors[j] == -1:
            colors[j] = 0
            queue = deque([j])
            while queue:
                cv = queue.popleft()
                for nv in adj[cv]:
                    if colors[nv] == -1:
                        colors[nv] = 1 - colors[cv]
                        queue.append(nv)
                    elif colors[cv] == colors[nv]:
                        is_bipartite_graph = False
                        break
            if not is_bipartite_graph:
                break
    
    if is_bipartite_graph:
        print("YES")
    else:
        print("NO")
                        

