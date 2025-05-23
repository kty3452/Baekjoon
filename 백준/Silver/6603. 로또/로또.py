# 로또

import sys

def user_input():
    return sys.stdin.readline().strip()

def backtrack(start, lotto_nums, temp_arr):
    if len(temp_arr) >= 6:
        print(*temp_arr)
        return
    for i in range(start, len(lotto_nums)):
        temp_arr.append(lotto_nums[i])
        backtrack(i + 1, lotto_nums, temp_arr)
        temp_arr.pop()


while True:
    lotto_nums = list(map(int, user_input().split()))
    if lotto_nums[0] == 0:
        break
    backtrack(1, lotto_nums, [])
    print()