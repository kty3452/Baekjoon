# 섬의 개수

from collections import deque
import sys
dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]

while True:
    temp = sys.stdin.readline().strip().split(' ')
    w = int(temp[0])
    h = int(temp[1])
    if(w == 0 or h == 0):
        break

    is_land = [list(map(int, sys.stdin.readline().strip().split(' '))) for _ in range(h)]
    visited = [[0] * w for _ in range(h)]

    count = 0
    for i in range(h):
        for j in range(w):
            if is_land[i][j] == 1 and visited[i][j] == 0:
                visited[i][j] = 1
                queue = deque()
                queue.append((i, j))
                while queue:
                    cy, cx = queue.popleft()
                    for dir in range(8):
                        nx, ny = cx + dx[dir], cy + dy[dir]
                        if 0 <= nx < w and 0 <= ny < h:
                            if is_land[ny][nx] == 1 and visited[ny][nx] == 0:
                                visited[ny][nx] = 1
                                queue.append((ny, nx))
                count += 1
    print(count)