from sys import stdin
n = int(input())
pair = int(input())
visited = [False for _ in range(n + 1)]
link = [[False for i in range(n + 1)] for j in range(n + 1)]
for i in range(1,n+1):
    link[i][i] = True
for _ in range(pair):
    a , b = map(int, stdin.readline().split())
    link[a][b] = True
    link[b][a] = True 
def dfs(c):
    visited[c] = True
    for i in range(1,n + 1):
        if link[c][i] and visited[i] == False:
            dfs(i)

dfs(1)
count = 0
for i in range(2, n + 1):
    if visited[i]:
        count += 1
print(count)
    

