import sys
input = sys.stdin.readline

N, M = map(int, input().split())
arr = []

def backtrack(start):
    if len(arr) == M:
        print(*arr)
        return
    for i in range(start, N + 1):  # ← start부터 시작
        arr.append(i)
        backtrack(i + 1)  # ← 다음은 i보다 큰 수만 사용
        arr.pop()

backtrack(1)
