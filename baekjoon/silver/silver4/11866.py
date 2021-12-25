n, k = map(int,input().split())
numbers = [i for i in range(1,n+1)]
p = []
point = k - 1

while numbers:
    p.append(numbers.pop(point))
    point += k - 1
    while point >= len(numbers) and numbers:
            point = point - len(numbers)


print('<', end = "")
for i in range(len(p)-1):
    print(p[i], ", ", sep = "", end = "")   

print(p[len(p)-1],'>', sep = '', end = '')
