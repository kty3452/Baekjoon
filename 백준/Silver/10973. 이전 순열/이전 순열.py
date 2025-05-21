# 이전 순열
import sys

def user_input():
    return sys.stdin.readline().strip()

N = int(user_input())
P = list(map(int, user_input().split()))

i = N - 2
while i >= 0 and P[i] <= P[i + 1]:
    i -= 1

if i == -1:
    print(-1)
else:
    j = N - 1
    while P[j] >= P[i]:
        j -= 1
    P[i], P[j] = P[j], P[i]

    P[i + 1:] = sorted(P[i + 1:], reverse=True)

    print(*P)