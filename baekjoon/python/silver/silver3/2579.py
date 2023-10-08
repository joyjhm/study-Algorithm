from sys import stdin
n = int(stdin.readline())
stair = []
max = [[0,0]]
stair.append(0)
for _ in range(n):
    stair.append(int(stdin.readline()))
    max.append([0,0])
for _ in range(2):
    stair.append(0)
    max.append([0,0])

x = 4
max[1] = [1,stair[1]] 
max[2] = [2,stair[1] + stair[2]]
if n >= 3:
    if stair[1] + stair[3] < stair[2] + stair[3]:
        max[3] = [2, stair[2] + stair[3]]
    else:
        max[3] = [1, stair[1] + stair[3]]
while x <= n:
    if max[x - 3][0] == 1:
        k = max[x - 3][1] + stair[x - 2] + stair[x]
        if k >= max[x][1]:
            max[x][1] = k
            max[x][0] = 1
    j = max[x - 3][1] + stair[x - 1] + stair[x]
    if j > max[x][1]:
        max[x][1] = j
        max[x][0] = 2
    k = max[x -2][1] + stair[x]
    if k >= max[x][1]:
        max[x][1] = k
        max[x][0] = 1
    if max[x-1][0] == 1:
        k = max[x-1][1] + stair[x]
        if k > max[x][1]:
            max[x][1] = k
            max[x][0] = 2
    x += 1

print(max[n][1])



# 더 나은 풀이
max[x][1] = max((max[x-3] + stair[x-1] + stair[x]), (max[x-2] + stair[x]))