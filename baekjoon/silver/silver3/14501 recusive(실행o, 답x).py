def work_max(t, p):
    global max
    if p > max:
        max = p
    else:
        pass
    if t > n:
        return
    else:
        if schedule[t][0] == 1:
            work_max(t + 1, p + schedule[t][1])
        elif schedule[t][0] + t <= n + 1:    
            work_max(schedule[t][0] + t, p + schedule[t][1])
            work_max(t + 1, p)
        else:
            return

n = int(input())
schedule = [[0,0]]
for _ in range(n):
    schedule.append(list(map(int,input().split())))
max = 0

work_max(1,0)
print(max)
    