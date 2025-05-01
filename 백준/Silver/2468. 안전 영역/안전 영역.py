# 안전 영역

from collections import deque
import sys
N = int(sys.stdin.readline().strip())

# 깊이에 따른 노드 파악
heights = [[0] for _ in range(101)]

# 해당 노드가 잠겼는지 아닌지 확인
node_alive = [1] * (N * N + 1)

# 가장 높은 노드의 높이
# 최소 1 이상
max_depth = 1

# 빗물의 깊이에 따른 연결 그래프의 개수
# 최소 1개는 존재(비가 오지 않을 경우 -> 1개)
max_count = 1

for i in range(N):
    temp = sys.stdin.readline().strip().split(' ')
    for j in range(1, N + 1):
        height_of_node = int(temp[j - 1])
        # 가장 깊은 깊이
        # 밑 코드에서 가장 깊은 깊이 직전까지 for문을 돌려야 하기 때문
        if max_depth < height_of_node:
            max_depth = height_of_node

        # i = 0 -> index 1 ~ 5, i = 1 -> index 6 ~ 10
        node_num = (i * N) + j 

        heights[height_of_node].append(node_num) 

adj = [[] for i in range(N * N + 1)]
for i in range(1, N * N + 1):
    # 가장 오른쪽이면 오른쪽에는 인접된 노드 부재
    if i % N != 0: 
        adj[i].append(i + 1)
    # 가장 왼쪽이면 왼쪽에는 인접된 노드 부재
    if i % N != 1: 
        adj[i].append(i - 1)
    # 가장 밑이면 밑에는 인접된 노드 부재
    if i <= N * N - N: 
        adj[i].append(i + N)
    # 가장 위이면 위에는 인접된 노드 부재
    if i > N: 
        adj[i].append(i - N)


# 각 빗물 깊이마다 실행(1 ~ max - 1)
for current_depth in range(1, max_depth): 
    visited = [0] * (N * N + 1)
    safe_area_count = 0
    # 현재 빗물 깊이와 같은 높이를 지닌 노드들은 전부 not alive 처리
    for i in heights[current_depth]: 
        node_alive[i] = 0
    # 이제 각 노드마다 bfs 실행
    for start_node in range(1, (N * N + 1)):
        # 방문하지 않았고, 잠기지 않은 노드들만 탐색
        # 방문했을 경우, 이미 다른 그래프에 연결
        # 잠겨있을 경우, 해당 노드는 없는 것과 마찬가지
        if not visited[start_node] and node_alive[start_node]:
            queue = deque()
            queue.append(start_node)
            visited[start_node] = 1
            while len(queue) > 0:
                current_node = queue.popleft()
                for next_node in adj[current_node]:
                    if not visited[next_node] and node_alive[next_node]:
                        visited[next_node] = 1
                        queue.append(next_node)
            safe_area_count += 1
    # 현재 빗물 깊이에 따른 안전 구역 개수와 
    # 현재까지의 최대 안전 구역 개수 비교
    if max_count < safe_area_count:
        max_count = safe_area_count


print(max_count)            
            
