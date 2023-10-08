from sys import stdin
from collections import deque
n, m, v = map(int, stdin.readline().split())
connect = [[] for i in range(n + 1)]
visit = [0 for _ in range(n + 1)]
queue = deque()
result = []

for _ in range(m):
    a, b = map(int, stdin.readline().split())
    connect[a].append(b)
    connect[b].append(a)
for i in range(1, n+1):
    connect[i] =sorted(connect[i])
def dfs(v):
    print(v, end = " ")
    visit[v] = 1
    for j in connect[v]:
        if not visit[j]:
            visit[j] = 1
            dfs(j)
            
def bfs(v):
    queue.append(v)

    while queue:
        x = queue[0]
        visit[x] = 1
        print(x, end = " ")
        for k in connect[x]:
            if visit[k] == 0 and k not in queue:
                queue.append(k)
        x = queue.popleft()

        

dfs(v)
print()
for i in range(1, n + 1):
    visit[i] = 0
bfs(v)
