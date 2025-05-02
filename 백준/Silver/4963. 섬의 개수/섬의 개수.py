# 섬의 개수

from collections import deque
import sys

while True:
    temp = sys.stdin.readline().strip().split(' ')
    w = int(temp[0])
    h = int(temp[1])
    if(w == 0 or h == 0):
        break

    visited = [0] * (w * h + 1)
    is_land = [0] * (w * h + 1)
    for i in range(h):
        temp = sys.stdin.readline().strip().split(' ')
        for j in range(1, w + 1):
            index = (i * w) + j
            is_land[index] = int(temp[j - 1])

    
    adj = [[] for i in range(w * h + 1)]
    for i in range(w * h + 1):
        if is_land[i] == 1:
            # 가장 오른쪽이면 오른쪽에는 인접된 노드 부재         
            if i % w != 0: 
                adj[i].append(i + 1)
            # 가장 왼쪽이면 왼쪽에는 인접된 노드 부재
            if i % w != 1: 
                adj[i].append(i - 1)
            # 가장 밑이면 밑에는 인접된 노드 부재
            if i <= w * h - w: 
                adj[i].append(i + w)
            # 가장 위이면 위에는 인접된 노드 부재
            if i > w: 
                adj[i].append(i - w)
            # 오른쪽 혹은 위쪽에 있는지 확인
            if i % w != 0 and i > w:
                adj[i].append(i - w + 1)
            # 왼쪽 혹은 위쪽에 있는지 확인
            if i % w != 1 and i > w:
                adj[i].append(i - w - 1)
            # 오른쪽 혹은 아래쪽에 있는지 확인
            if i % w != 0 and i <= w * h - w:
                adj[i].append(i + w + 1)
            # 왼쪽 혹은 아래쪽에 있는지 확인
            if i % w != 1 and i <= w * h - w:
                adj[i].append(i + w - 1)

    count = 0
    for i in range(1, w * h + 1):
        if is_land[i] == 1 and visited[i] == 0:
            visited[i] = 1
            queue = deque()
            queue.append(i)
            while len(queue):
                v = queue.popleft()
                for nv in adj[v]:
                    if is_land[nv] == 1 and visited[nv] == 0:
                        visited[nv] = 1
                        queue.append(nv)
            count += 1
    print(count)