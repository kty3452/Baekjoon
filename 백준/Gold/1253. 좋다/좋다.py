# 좋다

import sys

N = int(sys.stdin.readline().strip())
arr = list(map(int, sys.stdin.readline().strip().split()))
arr.sort()

last_idx = N - 1
same_area = [arr[0]]
gaps = []
gap = 0
count = 0

for i in range(N):
    gap += 1
    if i == last_idx:
        gaps.append(gap)
        break
    if arr[i] != arr[i + 1]:
        same_area.append(arr[i + 1])
        gaps.append(gap)
        gap = 0

for c_idx in range(len(gaps)):
    c_gap = gaps[c_idx]
    left_idx = 0
    right_idx = len(same_area) - 1
    while True:
        if left_idx == right_idx:
            if same_area[c_idx] == 0 and same_area[left_idx] == 0:
                if c_gap > 2:
                    count += c_gap
            elif gaps[left_idx] > 1 and same_area[c_idx] == same_area[left_idx] * 2:
                count += c_gap
            break
        
        if left_idx == c_idx:
            if gaps[c_idx] == 1:
                left_idx += 1
                continue
        elif right_idx == c_idx:
            if gaps[c_idx] == 1:
                right_idx -= 1
                continue
            
        sum = same_area[left_idx] + same_area[right_idx]

        if same_area[c_idx] < sum:
            right_idx -= 1
        elif same_area[c_idx] > sum:
            left_idx += 1
        else:
            count += c_gap
            break

print(count)