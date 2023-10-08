from sys import stdin
n , k = map(int, stdin.readline().split())
coin = []

for _ in range(n):
    coin.append(int(stdin.readline()))

coin.sort( reverse = True)
sum = 0
i = 0
count = 0
while sum != k:
    while sum + coin[i] <= k:
        count += 1
        sum += coin[i]
    
    i += 1
print(count)
