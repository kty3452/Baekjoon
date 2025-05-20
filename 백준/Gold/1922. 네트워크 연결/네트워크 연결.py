# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
# 최소신장트리 제작
# 최소신장트리의 간선 중 가장 긴 간선을 제외 해야하기에 크루스칼이 더 나은 선택
import sys
from collections import deque

def user_input():
    return sys.stdin.readline().strip()
def build_edges(N, M):
	edges = [0] * M
	for i in range(M):
		A, B, C = map(int, user_input().split())
		edges[i] = (A, B, C)
	return edges


N = int(user_input())
M = int(user_input())
parent = [i for i in range(N+1)]
edges = build_edges(N, M)
edges.sort(key = lambda x: x[2])
result = 0
count = 0

for v1, v2, w in edges:
	root_of_v1 = v1
	root_of_v2 = v2
	while True:
		if parent[root_of_v1] != root_of_v1:
			root_of_v1 = parent[root_of_v1]
		else:
			parent[v1] = root_of_v1
			break
	while True:
		if parent[root_of_v2] != root_of_v2:
			root_of_v2 = parent[root_of_v2]
		else:
			parent[v2] = root_of_v2
			break
	if root_of_v1 != root_of_v2: 
		root = min(root_of_v1, root_of_v2)
		parent[root_of_v1] = root
		parent[root_of_v2] = root
		result += w
		count += 1
		if count >= N - 1:
			break
print(result)
