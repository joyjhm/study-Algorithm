english_name = input()
num = int(input())
team_name = []       
team = []

for i in range(num):
    result = []     
    team_name.append(input())
    for s in 'LOVE':
            x = team_name[i].count(s) + english_name.count(s)
            result.append(x)

    a = 1
    for i in range(len(result) - 1):
        for j in range(i + 1, len(result)):
            a *= (result[i] + result[j])
    team.append(a % 100)

answer = []
for j in range(len(team)):
    if team[j] == max(team):
        answer.append(team_name[j])

print(min(answer))