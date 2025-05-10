# 기타 레슨

import sys

def input():
    return sys.stdin.readline().strip()

N, M = map(int, input().split())

classes = list(map(int, input().split()))

# N개 만큼 만드려면 최소 가장 긴 영상의 길이 만큼 필요 
low_min = max(classes)
# 1개의 영상으로 만드려면 다 더한 길이 만큼 필요
high_min = sum(classes)
result = 0

while low_min <= high_min:
    mid = (low_min + high_min) // 2
    count = 0
    temp = 0
    for class_len in classes:
        if temp + class_len > mid:
            temp = 0
            count += 1
        temp += class_len
    # 1. 만약 temp값이 mid와 같거나 작을 경우,
    # count를 1 추가해야 하지만 추가하지 않음
    # 2. 만약 temp값이 mid보다 클 경우,
    # count를 1 추가 하지만 나머지 값에 대해서도
    # 1 추가 해야함
    count += 1

    if count > M:
        low_min = mid + 1
    else:
        result = mid
        high_min = mid - 1
print(result)

