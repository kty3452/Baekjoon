# 수 찾기

import sys

N = int(sys.stdin.readline().strip())

arr = list(map(int, sys.stdin.readline().strip().split()))
arr.sort()

M = int(sys.stdin.readline().strip())
result = [0] * M

def search(val, left = 0, right = len(arr) - 1):
    if left > right:
        return 0
    
    mid = (left + right) // 2
    if arr[mid] == val:
        return 1
    elif arr[mid] > val:
        return search(val, left = left, right = mid - 1)
    else:
        return search(val, left = mid + 1, right = right)

# 반복문 버전
# def search(val):
#     left, right = 0, len(arr) - 1
#     while left <= right:
#         mid = (left + right) // 2
#         if arr[mid] == val:
#             return 1
#         elif arr[mid] > val:
#             right = mid - 1
#         else:
#             left = mid + 1
#     return 0

# bisect 버전
# import sys
# import bisect

# input = sys.stdin.readline

# N = int(input())
# A = sorted(map(int, input().split()))

# M = int(input())
# targets = list(map(int, input().split()))

# for t in targets:
#     # 배열 어디에 끼워 넣어야하는지 위치를 알려줌 
#     idx = bisect.bisect_left(A, t)
#     print(1 if idx < N and A[idx] == t else 0)



for i in list(map(int, sys.stdin.readline().strip().split())):
    print(search(i))