a = []
for i in range(0,8):
    a.append(input())

count = 0
for i in range(0,8):
    for j in range(0,8):
        if a[i][j] == 'F':
            if i % 2 == 0 and j % 2 == 0:
                count += 1
            elif i % 2 == 1 and j % 2 == 1:
                count += 1
print(count)