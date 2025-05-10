# 용돈 관리

import sys

def input():
    return sys.stdin.readline().strip()

N, M = map(int,input ().split())

amounts = [int(input()) for _ in range(N)]

low = max(amounts)
high = 1000000000
result = 0

while low <= high:
    refresh_count = 1 
    mid = (low + high) // 2
    cur_k = mid
    for amount in amounts:
        if cur_k < amount:
            cur_k = mid
            refresh_count += 1
        cur_k -= amount
    
    if refresh_count > M:
        low = mid + 1
    else:
        result = mid
        high = mid - 1

print(result)
