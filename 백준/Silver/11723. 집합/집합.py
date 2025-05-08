# 집합

import sys

def input():
    return sys.stdin.readline().strip()

M = int(input())
arr = [0 for _ in range(21)]

def add(idx):
    arr[idx] = 1
def remove(idx):
    arr[idx] = 0
def check(idx):
    if arr[idx]:
        return 1
    else:
        return 0
def toggle(idx):
    arr[idx] = 1 - arr[idx]
def all():
    global arr
    arr = [1 for _ in range(21)]
def empty():
    global arr
    arr = [0 for _ in range(21)]


for _ in range(M):
    op = input().split()
    name = op[0]
    if name == 'add':
        idx = int(op[1])
        add(int(idx))
    elif name == 'remove':
        idx = int(op[1])
        remove(idx)
    elif name == 'check':
        idx = int(op[1])
        print(check(idx))
    elif name == 'toggle':
        idx = int(op[1])
        toggle(idx)
    elif name == 'all':
        all()
    else:
        empty()
    