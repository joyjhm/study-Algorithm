s1, s2,s3 = map(int, input().split())
sum = []

for i in range(0, s1 + s2 + s3 + 1):
    sum.append(0)

for i in range(1, s1 + 1):
    for j in range(1, s2 + 1):
        for k in range(1, s3 + 1):
            x = i + j + k
            sum[x] += 1
            
print(sum.index(max(sum)))
            



