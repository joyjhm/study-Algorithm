m, n = map(int, input().split())
num = [1] * 1000001
num[1] = 0
for i in range(2,n + 1):
    if num[i]:
        for j in range(i * 2, n + 1, i):
            num[j] = 0

for i in range(m, n + 1):
    if num[i]:
        print(i) 

