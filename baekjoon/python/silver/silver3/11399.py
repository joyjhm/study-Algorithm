n = int(input())
p = [i for i in list(map(int,input().split()))]
p = sorted(p)
sum = 0
for i in range(n):
    for j in range(i+1):
        sum += p[j]
print(sum)