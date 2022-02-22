from sys import stdin

n, s = map(int, stdin.readline().split())
a = list(map(int, stdin.readline().split()))
b = []
count = 0
def sol(index):
    global count
    if sum(b) == s and b:
        count += 1
    for i in range(index, n):
        b.append(a[i])
        sol(i + 1)
        b.pop()

sol(0)
print(count)