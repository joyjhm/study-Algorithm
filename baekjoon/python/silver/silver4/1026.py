from sys import stdin
n = int(input())

a = list(map(int,stdin.readline().split()))
b = list(map(int,stdin.readline().split()))

a = sorted(a)
b = sorted(b)
b.reverse()

sum = 0
for i in range(n):
    sum += a[i] * b[i]
print(sum)