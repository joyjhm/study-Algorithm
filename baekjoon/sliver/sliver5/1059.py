L = int(input())
s = list(map(int,input().split()))
n = int(input())

minus_differ = -1000
plus_differ = 1000
max = 0
min = 0
result = 0
for i in s:
    if n - i < 0 and minus_differ < n - i:
        minus_differ = n - i
        max = i
    elif n - i > 0 and plus_differ > n - i:
        plus_differ = n - i
        min = i
    elif n - i == 0:
        print(0)
        exit()
max -= 1
min += 1

while min <= n:
    for i in range(n, max + 1):
        if min != i:
            result += 1
    min += 1

print(result)