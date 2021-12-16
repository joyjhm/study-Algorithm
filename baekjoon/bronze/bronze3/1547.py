def swap(x, y, cup):
    a = cup.index(x)
    b = cup.index(y)
    temp = cup[a]
    cup[a] = cup[b]
    cup[b] = temp
    return cup

cup = [1,2,3]
m = int(input())

for i in range(m):
    x, y= map(int,input().split())
    cup = swap(x, y,cup)
print(cup[0])
    