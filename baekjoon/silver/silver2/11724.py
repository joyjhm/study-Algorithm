from sys import stdin
n, m = map(int, stdin.readline().split())
grape = [[0 for i in range(n + 1)] for j in range(n + 1)]
visited = [0] * (n + 1)
visited[0] = 1 
for _ in range(m):
    a, b = map(int, stdin.readline().split())    
    grape[a][b] = 1
    grape[b][a] = 1
queue = [1]
connect = 1
while True:
    v = queue.pop(0)
    visited[v] = 1
    if all(visited):
        break
    for i in range(len(grape[v])):
        if grape[v][i] == 1 and not visited[i] and i not in queue:
            queue.append(i)
    
    if not queue:
        queue.append(visited.index(0))
        connect += 1
    
print(connect)
