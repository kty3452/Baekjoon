# 퇴사
import sys

def user_input():
    return sys.stdin.readline().strip()

N = int(user_input())
arr = [tuple(map(int, user_input().split())) for _ in range(N)]
DP = [[0] * (N + 1) for _ in range(N + 1)]

for i in range(1, N + 1):
    T, P = arr[i - 1]
    for j in range(1, N + 1):
        if(i + T - 1 == j):
            DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - T] + P)
        else:
            DP[i][j] = max(DP[i][j - 1], DP[i - 1][j])
        

# for i in range(N + 1):
#     print(DP[i])
print(DP[N][N])