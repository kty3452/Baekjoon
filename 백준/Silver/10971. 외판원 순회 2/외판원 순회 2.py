# 외판원 순회2 (리팩토링 버전)
import sys

min_cost = float('inf')

def user_input():
    return sys.stdin.readline().strip()

def backtrack(N, W, start, current, used, path_sum, depth):
    global min_cost

    # 모든 도시 방문 완료 후 시작 도시로 복귀 가능한 경우
    if depth == N - 1:
        if W[current][start]:
            total_cost = path_sum + W[current][start]
            min_cost = min(min_cost, total_cost)
        return

    for next_city in range(N):
        if not used[next_city] and W[current][next_city] != 0:
            used[next_city] = True
            backtrack(N, W, start, next_city, used, path_sum + W[current][next_city], depth + 1)
            used[next_city] = False

N = int(user_input())
W = [list(map(int, user_input().split())) for _ in range(N)]

for start in range(N):
    used = [False] * N
    used[start] = True
    backtrack(N, W, start, start, used, 0, 0)

print(0 if min_cost == float('inf') else min_cost)
