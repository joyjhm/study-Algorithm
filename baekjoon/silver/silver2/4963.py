from sys import stdin
queue = []
dx = [-1, 0, 1, -1, 1, -1, 0, 1]
dy = [-1, -1, -1, 0, 0, 1, 1, 1]

def bfs(x, y, rectangle):
    while queue:
        x, y = queue.pop(0)
        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= h or ny < 0 or ny >= w:
                continue 
            if rectangle[nx][ny] == 1:
                rectangle[nx][ny] = 0
                queue.append((nx,ny))
    return

while True:
    ground = 0
    w, h = map(int, stdin.readline().split())
    if w == 0 and h == 0:
        break
    rectangle = []
    visited = []
    for i in range(h):
        rectangle.append(list(map(int, stdin.readline().split())))
        visited.append([0 for j in range(w)])
    for x in range(h):
        for y in range(w):
            if rectangle[x][y] == 1:
                queue.append((x, y))
                bfs(x, y, rectangle)
                ground += 1
    
    print(ground)
        
    
    
