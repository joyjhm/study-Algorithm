from sys import stdin
t = int(input())
p = [0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9]
x = 11
while x <= 100:
    p.append(p[x - 5] + p[x - 1]) 
    x += 1
    
for _ in range(t):
    n = int(stdin.readline())
    print(p[n])


