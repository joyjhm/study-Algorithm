import sys
n = int(input())
dots = []
for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    dots.append((a, b))

dots = sorted(dots)
for a, b in dots:
    print(a, b, sep = " ")