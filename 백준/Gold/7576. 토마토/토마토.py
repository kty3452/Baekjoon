# 토마토(2차원)

from collections import deque
import sys

M, N = map(int, sys.stdin.readline().strip().split())
visited = [[0] * (M + 2) for _ in range(N + 2)]
grape = [[-1] * (M + 2) for _ in range(N + 2)]
dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]
ny, nx = 0, 0
max_count = 0
start_is_one = []

for i in range(1, N + 1):
    grape[i][1:M+1] = list(map(int, sys.stdin.readline().strip().split()))
    # 리스트의 값과 값의 따른 인덱스 출력 (인덱스, 값)
    # start = 1은 인덱스 번호를 1부터 시작하겠다는 의미
    # enumerate(grape[i])와 결과는 똑같지만 이는 쓸데없는 패딩값을 읽음
    # for j, val in enumerate(grape[i][1:M+1], start=1):
    #     if val == 1:
    #         start_is_one.append((i, j))
    start_is_one.extend((i, j) for j, val in enumerate(grape[i][1:M+1], start=1) if val == 1)

# 리스트를 넣으면 한번에 됨
queue = deque(start_is_one) 
for i, j in start_is_one:
    visited[i][j] = 1
for i, j in start_is_one:
    visited[i][j] = 1
    while queue:
        cy, cx = queue.popleft()
        for k in range(4):
            ny, nx = cy + dy[k], cx + dx[k]
            if visited[ny][nx] == 0 and grape[ny][nx] == 0:
                visited[ny][nx] = visited[cy][cx] + 1
                # -1을 해주는 이유는 visited의 첫번째 값이 1부터 시작하기 때문
                # 그러나 토마토는 0부터 시작
                max_count = max(max_count, visited[ny][nx] - 1)
                grape[ny][nx] = 1
                queue.append((ny, nx))

    
for i in range(1, N + 1):
    if 0 in grape[i][1:M+1]:
        max_count = -1
        break
print(max_count)
                
