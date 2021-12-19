n = int(input())
height = []
weight = []
rank = []
for i in range(n):
    a, b = map(int,input().split())
    weight.append(a)
    height.append(b)
    rank.append(0)

count = 1
while any(height):
    count2 = 1
    x = height.index(max(height))
    y = weight.index(max(weight))
    if x == y:
        rank[x] = count
        height[x] = 0
        weight[y] = 0
    else:
        for i in range(n):
            if weight[x] < weight[i]:
                rank[x] = count
                height[i] = 0
                weight[i] = 0
                rank[i] = count
                count2 += 1
        height[x] = 0
        weight[x] = 0
    count += count2

for i in rank:
    print(i, end= " ")
        
        
    
        

    
    
        
