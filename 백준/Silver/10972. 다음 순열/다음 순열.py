# 다음 순열
# import sys

# def user_input():
#     return sys.stdin.readline().strip()

# N = int(user_input())
# P = list(map(int, user_input().split()))
# is_final = True

# for i in reversed(range(N - 1)):
#     if P[i] < P[N - 1]:
#         P[i], P[N - 1] = P[N - 1], P[i]
#         P[i+1:N] = sorted(P[i+1:N])
#         print(*P)
#         exit()
# print(-1)

import sys

def user_input():
    return sys.stdin.readline().strip()

N = int(user_input())
P = list(map(int, user_input().split()))

# Step 1: 뒤에서부터 i 찾기
i = N - 2
while i >= 0 and P[i] >= P[i + 1]:
    i -= 1

if i == -1:
    print(-1)
else:
    # Step 2: i보다 큰 수 중 가장 작은 값(j)을 뒤에서 찾기
    j = N - 1
    while P[j] <= P[i]:
        j -= 1

    # Step 3: i, j swap
    P[i], P[j] = P[j], P[i]

    # Step 4: i 이후를 정렬
    P[i + 1:] = sorted(P[i + 1:])

    print(*P)
