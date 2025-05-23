# 외판원 순회2

import sys

def user_input():
    return sys.stdin.readline().strip()

def backtrack(N, W, used, only_use, arr, min_cost, start):
             
    if len(arr) == N - 1:
        if W[only_use][start]:
            if min_cost[0] > sum(arr) + W[only_use][start]:
                min_cost[0] = sum(arr) + W[only_use][start]
        return
    for i in range(N):
        if len(arr) == 0:
            used[start] = False
            start = i
            used[start] = True
            only_use = start
        if i == only_use:
            for j in range(N):
                if used[j] or W[i][j] == 0:
                    continue
                used[j] = True
                arr.append(W[i][j])
                backtrack(N, W, used, j, arr, min_cost, start)
                arr.pop()
                used[j] = False

N = int(user_input())
W = [list(map(int, user_input().split())) for _ in range(N)]
min_cost = [10000001]
backtrack(N, W, [False] * N, -1, [], min_cost, -1)
if min_cost[0] > 10000001:
    min_cost = 0
print(min_cost[0])