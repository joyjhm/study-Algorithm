num = int(input())
student = []
check = []
for b in range(num):
    student.append(list(map(int,input().split())))
    check.append([])
    for c in range(num):
        if b == c:
            check[b].append(False)
        else:
            check[b].append(True)

for i in range(5):
    count = [0,0,0,0,0,0,0,0,0,0,0]
    for k in range(1,10):
        for j in range(num):
            if student[j][i] == k:
                count[k] += 1
    for b in range(1,10):
        if count[b] > 1:
            li = []
            for a in range(num):
                if student[a][i] == b: 
                    li.append(a)
                    for x in li:
                        for y in li:
                            check[x][y] = False

same = []
for i in range(num):
    same.append(check[i].count(False))
print(same.index(max(same)) + 1)
 
                    
                

        
             
            