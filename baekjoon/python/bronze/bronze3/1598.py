a = list(map(int, input().split()))
b = []
for i in range(0,2):
    if a[i] % 4 == 0:
        b.append([a[i] // 4 - 1, 0])
    else:
        b.append([a[i] // 4, 4 - (a[i] % 4)])

print(abs(b[1][0]-b[0][0]) + abs(b[1][1]-b[0][1]))

