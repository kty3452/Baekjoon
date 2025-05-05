# 단지번호붙이기

from collections import deque
import sys

N = int(sys.stdin.readline().strip())
visited = [[0] * (N + 2) for _ in range(N + 2)]
grape = [[0] * (N + 2) for _ in range(N + 2)]
dangi_count = 0
dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]
result_of_house = []

for i in range(1, N + 1):
    grape[i][1:N+1] = list(map(int, sys.stdin.readline().strip()))


for i in range(1, N + 1):
    for j in range(1, N + 1):
        if not visited[i][j] and grape[i][j] == 1:
            dangi_count += 1 
            house_count = 1
            visited[i][j] = 1
            queue = deque([(i, j)])
            while queue:
                cy, cx = queue.popleft()
                for k in range(4):
                    ny, nx = cy + dy[k], cx + dx[k]
                    if not visited[ny][nx] and grape[ny][nx] == 1:
                        queue.append((ny, nx))
                        visited[ny][nx] = 1
                        house_count += 1
            result_of_house.append(house_count)
result_of_house.sort()
print(dangi_count)
for count in result_of_house:
    print(count)
