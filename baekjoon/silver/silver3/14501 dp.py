n = int(input())
schedule = [[0,0]]
sum = [0]
for _ in range(n):
    schedule.append(list(map(int,input().split())))
    sum.append(0)
sum.append(0)
x = 1
while x <= n:
    if x + schedule[x][0] <= n + 1:
        if sum[x] + schedule[x][1] > sum[x + schedule[x][0]]:
            sum[x + schedule[x][0]] = sum[x] + schedule[x][1]
    if schedule[x][0] + 1 <= n + 1:
        if sum[x] > sum[x + 1]:
            sum[x + 1] = sum[x]
    x += 1

print(max(sum))
    