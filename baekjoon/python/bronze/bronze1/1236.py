m, n = map(int, input().split())
castle = []
r = []

x = 0
count = 0
for i in range(m):
    castle.append(input())

for i in range(m):
    r.append([])
    for j in range(n):
        if castle[i][j] == '.':
            r[i].append(False)
        else:
            r[i].append(True)

for a in range(m):                           # 행, 열 모두 .만 있는 경우
    if r[a].count(True) == 0:
        x = a
        for j in range(n):
            col = 0
            for i in range(m):
               if r[i][j] == False:
                   col += 1
            if col == m:
                y = j
                r[x][y] = True
                count += 1
                break
 
for i in range(m):                          # 행만 .이 있는 경우
    if r[i].count(True) == 0:
        r[i][0] = True
        count += 1
    
for j in range(n):                          # 열만 .이 있는 경우
    col = 0
    for i in range(m):
       if r[i][j] == False:
           col += 1
    if col == m:
        count += 1
        r[0][j] = True
      
print(count)
