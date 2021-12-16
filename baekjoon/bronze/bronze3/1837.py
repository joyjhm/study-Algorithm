import sys
input = sys.stdin.readline
p, k = map(int, input().split())

i = 2
while(i < k):
    if p % i == 0:
        x = i
        y = p // i
        print('BAD',min(x, y))
        break
    else:
        i += 1 

if i >= k:
    print('GOOD')
