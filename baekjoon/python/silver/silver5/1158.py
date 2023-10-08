N, K = map(int, input().split())
n = []
result = []
for i in range(1, N + 1):
    n.append(i)
for j in range(N):
    
    if K  <= len(n): 
        result.append(n[K-1])
        n = n[K:] + n[:K-1]
    else:
        x = (K % len(n)) - 1
        result.append(n[x])
        if x == 0:
            n = n[x + 1:]
        elif x == -1:
            n = n[0:len(n)-1]
        else:
            n = n[x + 1:] + n[:x]

print('<', end = "")
for i in range(len(result)-1):
    print(result[i], end=", ")
print(result[len(result)-1], end="")
print('>')
        