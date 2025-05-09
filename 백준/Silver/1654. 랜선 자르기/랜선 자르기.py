# 랜선 자르기

import sys

def input():
    return sys.stdin.readline().strip()

K, N = map(int, input().split())
target_count = N
result = 1

cables = list(int(input()) for _ in range(K))

# 랜선을 0cm로 자를 수는 없음
min_len = 1

# K <= N이긴 하지만
# 2 5
# 1
# 1000
# 같은 극단적인 케이스가 있을 수 있음
max_len = max(cables)

while min_len <= max_len:
    mid_len = (max_len + min_len) // 2
    total_cable_count = sum((cable_len // mid_len) for cable_len in cables)

    # 잘린 랜선의 개수와 목표 값이 같을 수도 있음.
    # 하지만 mid_len은 원하는 랜선 개수를 만들면서
    # 동시에 최대 값이어야 함(최대한 낭비가 없어야 함)
    # 그렇기에 최대 값까지(끝까지) 탐색
    # (부가 설명)
    # 나무 자르기에서는 cur_h가 늘어나면 
    # 잘린 나무의 길이는 무조건 줄어든다는 보장이 있었음.
    # 그러나 여기서는 목표 개수를 채웠다고 하더라도
    # 그게 최대한 랜선의 낭비 없이 잘랐는지는 미지수임.
    # 그러므로 끝까지 탐색
    if total_cable_count >= target_count:
        result = mid_len
        min_len = mid_len + 1
    # mid_len은 정답이 될 수 없기 때문에 제외하고 탐색
    # 다시 말하자면 min_len ~ mid_len - 1 중에서 정답을 탐색
    # 왜냐하면 잘린 랜선의 개수가 목표보다 적으면 정답이 될 수 없기 때문
    else:
        max_len = mid_len - 1

print(result)