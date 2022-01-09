from sys import stdin
k, n = map(int, stdin.readline().split())
line = [int(stdin.readline()) for _ in range(k)]

x = min(line)
y = max(line)
while True:
    count = 0
    for i in line:
        count += i // x
        count += i // y
    if count == n:
        break
    count += x // 2
    count += y // 2
    