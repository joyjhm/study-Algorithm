n = int(input())
people = []
height_rank = [101]
weight_rank = [101]
rank = [101]
for i in range(n):
    people.append(list(map(int,input().split())))
    people[i].append(i+1)
    height_rank.append(i+1)
    weight_rank.append(i+1)
    rank. append(0)

for i in range(n-1):
    for j in range(i+1, n):
        if people[i][0] < people[j][0]:
            temp = people[i]
            people[i] = people[j]
            people[j] = temp
for a in range(n):
    height_rank[people[a][2]] = a + 1
            
for i in range(n-1):
    for j in range(i+1, n):
        if people[i][1] < people[j][1]:
            temp = people[i]
            people[i] = people[j]
            people[j] = temp
for a in range(n):
    weight_rank[people[a][2]] = a + 1
    
for a in range(1,n+1):
    height_rank[a] = height_rank[a] + weight_rank[a]

count = 1
while count <= n:
    r = []
    x = min(height_rank)
    count2 = 0
    for a in range(1,len(height_rank)):
        if height_rank[a] == x:
            r.append(a)
            count2 += 1
    if count2 == 1:
        rank[r[0]] = count
        height_rank[r[0]] = 51
        count += 1
    else:
        while r:        
            rank[r[0]] = count
            height_rank[r[0]] = 51
            r.pop(0)
        count += count2

for i in range(1,n+1):
    print(rank[i], end= " ")
   
        



    