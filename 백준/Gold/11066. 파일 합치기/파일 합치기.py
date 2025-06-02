# 파일 합치기
# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
# dp[i][j]는 i ~ j번째까지 합쳤을 때의 최소 비용
import sys

def user_input():
    return sys.stdin.readline().strip()

def sum_array(arr):
	sum_arr = [0]
	for i in arr:
		sum_arr.append(sum_arr[-1] + i)
	return sum_arr

def make_new_file(i, j, sum_arr):
	return sum_arr[j + 1] - sum_arr[i]

# DP[i][k] + DP[k+1][j] + sum(arr[i:j+1])
# i ~ k까지 합칠 때까지 쓰인 최소 비용용 + k+1~j까지 합칠 때까지 쓰인 최소 비용 + 두 파일을을 합쳐서 새로운 파일을 만드는 데에 걸리는 비용용
# k값을 i ~ j까지 계속 옮기면서, 어떤 식으로 조합해야 최소 비용이 쓰이는 지를 검사하고 이를 적용
# 계속 반복

T = int(user_input())

for _ in range(T):
	N = int(user_input())
	arr = list(map(int, user_input().split()))
	sum_arr = sum_array(arr)
	DP = [[0] * N for _ in range(N)]

	for length in range(2, N + 1):
		for i in range(N - length + 1):
			j = i + length - 1
			DP[i][j] = float('inf')
			cost = make_new_file(i, j, sum_arr)
			for k in range(i, j):
				DP[i][j] = min(DP[i][j], DP[i][k] + DP[k+1][j] + cost)

	# 1번부터 N번 파일까지 합치는 데에 쓰이는 최소 비용
	print(DP[0][N - 1])
