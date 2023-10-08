from sys import stdin
n = int(stdin.readline())
s = []
for _ in range(n):
    s.append(list(map(int,stdin.readline().split())))
min = 200
member = n // 2
t = [i for i  in range(0,n)]
member = [i for i in range(0,member)]
start_team = []


def selectTeam(start, num):
    global min
    if num == 0:
        a = 0
        b = 0
        for i in range(len(start_team) - 1):
            for j in range(i + 1, len(start_team)):
                a += s[start_team[i]][start_team[j]] + s[start_team[j]][start_team[i]]
        link_team = list(set(t) - set(start_team))
        for x in range(len(link_team) - 1):
            for y in range(x + 1, len(link_team)):
                b += s[link_team[x]][link_team[y]] + s[link_team[y]][link_team[x]]
        if abs(a- b) < min:
            min = abs(a - b)
        return
    else:
        for i in range(start,n):
            start_team.append(i)
            selectTeam(i + 1, num - 1)    
            start_team.pop()
            
selectTeam(0, n // 2)
print(min)

 
            
    

