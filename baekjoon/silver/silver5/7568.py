n = int(input())
height = []
weight = []
rank = []
for i in range(n):
    a, b = map(int,input().split())
    weight.append(a)
    height.append(b)
    rank.append(0)
count = 0
while count < n:
    for i in range(n):
        if count != i:
            if height[i] > height[count] and weight[i] > weight[count]:
                rank[count] += 1
    count += 1
for i in range(n):
    rank[i] += 1 
    
for i in rank:
    print(i, end= " ")
        
        
    
        

    
    
        
