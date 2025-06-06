# 1, 2, 3 더하기
import sys
sys.setrecursionlimit(10000)

def input():
    return sys.stdin.readline().strip()

dp = [0] * 10001
dp[0] = 1

def top_down(n):
    if n < 0:
        return 0
    if dp[n]:
        return dp[n]
    dp[n] = top_down(n-1) + top_down(n-2) + top_down(n-3)
    return dp[n]

T = int(input())
for _ in range(T):
    n = int(input())
    dp = [0] * (n+3)  # 입력마다 초기화
    dp[0] = 1
    print(top_down(n))