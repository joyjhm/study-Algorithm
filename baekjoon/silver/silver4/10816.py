from sys import stdin
n = int(stdin.readline())
a = list(map(int, stdin.readline().split()))
m = int(stdin.readline())
b = list(map(int,stdin.readline().split()))
count_b = [0] * 20000001

for i in a:
    count_b[i] += 1

for j in b:
    print(count_b[j], end = ' ')
