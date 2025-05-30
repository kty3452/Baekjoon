# 외판원 순회2

import sys

min_cost = 10000001

def user_input():
    return sys.stdin.readline().strip()

# def backtrack(N, W, used, only_use, arr, min_cost, start):
#     if len(arr) == N - 1:
#         if W[only_use][start]:
#             if min_cost[0] > sum(arr) + W[only_use][start]:
#                 min_cost[0] = sum(arr) + W[only_use][start]
#         return
#     for i in range(N):
#         if len(arr) == 0:
#             used[start] = False
#             start = i
#             used[start] = True
#             only_use = start
#         if i == only_use:
#             for j in range(N):
#                 if used[j] or W[i][j] == 0:
#                     continue
#                 used[j] = True
#                 arr.append(W[i][j])
#                 backtrack(N, W, used, j, arr, min_cost, start)
#                 arr.pop()
#                 used[j] = False

def backtrack(N, W, start, prev, used, arr):
    if len(arr) == N - 1:
        global min_cost
        if W[prev][start]:
            if min_cost > sum(arr) + W[prev][start]:
                min_cost = sum(arr) + W[prev][start]
        return
    for next in range(N):
        if used[next] or W[prev][next] == 0:
            continue
        used[next] = True
        arr.append(W[prev][next])
        backtrack(N, W, start, next, used, arr)
        arr.pop()
        used[next] = False
        
N = int(user_input())
W = [list(map(int, user_input().split())) for _ in range(N)]
# min_cost = [10000001]

# backtrack(N, W, [False] * N, -1, [], min_cost, -1)
# if min_cost[0] > 10000001:
#     min_cost[0] = 0
# print(min_cost[0])


for start in range(N):
    used = [False] * N
    used[start] = True
    arr = []
    prev = start
    backtrack(N, W, start, prev, used, arr)

if min_cost > 10000001:
    min_cost = 0
print(min_cost)