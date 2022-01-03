from sys import stdin
n = int(input())
p = []
s = []
result = []
numbers = [i for i in range(0, n+1)]
for _ in range(n):
    p.append(int(stdin.readline()))
x = 1
index = 0
b = True
while b and (x <= n  or s) :
    if x <= n and numbers[x] == p[index]:
        result.append('+')
        result.append('-')
        x += 1
        index += 1
    elif s and s[len(s)-1] == p[index]:
        s.pop()
        result.append('-')
        index += 1
    elif x <= n and numbers[x] != p[index]:
        s.append(numbers[x])
        result.append('+')
        x += 1
    else:
        b = False
if b:
    for i in result:
        print(i)
else:
    print('NO')