# 1, 2, 3 더하기 3
import sys

def input():
    return sys.stdin.readline().strip()

dp = [0] * 1000001
dp[1] = 1
dp[2] = 2
dp[3] = 4

def bottom_up():
    for i in range(4, 1000001):
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009

T = int(input())
bottom_up()

for _ in range(T):
    n = int(input())
    print(dp[n])