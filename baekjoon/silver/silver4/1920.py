from sys import stdin
n = int(input())
a = set(map(int, stdin.readline().split()))
m = int(input())
b = list(map(int, stdin.readline().split()))

for i in b:
    if i in a:
        print(1)
    else:
        print(0)