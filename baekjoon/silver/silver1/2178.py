from sys import stdin
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
mirror = []
pop = [(0,0)]
n, m = map(int, stdin.readline().split())

for _ in range(n):
    mirror.append(list(map(int, input())))
    
def bfs():
    while pop:
        x, y = pop.pop(0)
        for i in range(4):
            a = x + dx[i]
            b = y + dy[i]
            if a < 0 or b < 0 or a >= m or b >= n:
                continue
            if mirror[b][a] == 0:
                continue
            if mirror[b][a] == 1:
                mirror[b][a] = mirror[y][x] + 1
                pop.append((a, b))
    return mirror[n-1][m-1]

print(bfs())