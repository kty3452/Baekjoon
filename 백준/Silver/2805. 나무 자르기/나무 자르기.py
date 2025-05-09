# 나무 자르기

import sys

def input():
    return sys.stdin.readline().strip()

N, M = map(int, input().split())
result = 0

trees = list(map(int, input().split()))
min_len = 0
max_len = max(trees)

while min_len <= max_len:
    cur_h = (max_len + min_len) // 2

    total_len = sum(tree - cur_h for tree in trees if tree > cur_h)

    if total_len == M:
         result = cur_h
         break
    elif total_len > M:
        result = cur_h
        min_len = cur_h + 1
    else:
        max_len = cur_h - 1

print(result)
    
