from sys import stdin
n = int(stdin.readline())
a = list(map(int, stdin.readline().split()))
s = sum(a)
result = [0 for i in range(n)]
result[0] = a[0]
for i in range(n - 1):
    result[i + 1] = max(result[i] + a[i + 1], a[i + 1])

print(max(result))

