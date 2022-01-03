from sys import stdin
n = int(input())
pair = int(input())
p = []
p.append([])
for i in range(n):
    p.append([i + 1])

for _ in range(pair):
    a, b = map(int, stdin.readline().split())
    x = min(a, b)
    y = max(a, b)
    
    if p[y][0] < p[x][0]:
        k = p[x][0]
        while p[k]:
            s = p[k].pop()
            if p[k]:
                p[s][0] = [y][0]
            p[p[y][0]].append(s)
        p[k].append(p[y][0])
    elif p[y][0] > p[x][0]:
        k = p[y][0]
        while p[k]:
            s = p[k].pop()
            if p[k]:
                p[s][0] = p[x][0]
            p[p[x][0]].append(s)
        p[k].append(p[x][0])

print(len(p[1]) - 1)
