# # K번째 수

# base_idx = 0
# search_end = False
# search_arr = []
# x = 0
# y = 1
# for i in range(1, N + 1):
#     # 자연수만 계산하기 때문에 1부터 탐색
#     base_idx += i
#     x += 1
#     if(base_idx >= k):
#         base_idx -= i
#         search_end = True
#         break
# if not search_end:
#     for i in reversed(range(1, N - 1)):
#         base_idx += i
#         x += 1
#         if(base_idx >= k):
#             base_idx -= i
#             break

# print(base_idx)
# if x > N:
#     y = x - N + 1
#     x = N

# while x > 1 and y <= N:
#     search_arr.append(x * y)
#     x, y = x - 1, y + 1

# search_arr.sort()

# print(search_arr[k - base_idx])

import sys

def input():
    return sys.stdin.readline().strip()

N = int(input())
k = int(input())

min_num = 1
max_num = N * N
result = 0

while min_num <= max_num:
    mid_num = (min_num + max_num) // 2
    total_count = 0
    for i in range(1, N + 1):
        # j * i <= mid
        # -> j <= mid // i
        # 즉 다시 말해 특정 i값을 지닌 행에서
        # 어느정도의 j 값까지가 mid_num보다 작거나 같은 지를 검사.
        # 따라서 한 행에 몇 개의 값이 mid_num보다 같은지를 알 수 있음.
        # 이는 A[i][j]값이 i * j로 결정되기 때문에 가능한 방법
        total_count += min(N, (mid_num // i))

    if total_count < k:
        min_num = mid_num + 1
    else:
        result = mid_num
        max_num = mid_num - 1

print(result)