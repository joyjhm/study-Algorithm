import sys

N = int(sys.stdin.readline())
n = 0
a = [1,1]
count = 1
sum = 2
x = 0
while n < N and N != 1:
    if x == count and sum % 2 == 0:
        sum += 1
        count += 1
        a[0] = 1
        a[1] = sum - 1
        x = 1
        n += 1
    elif x != count and sum % 2 == 0:
        x += 1
        a[0] -= 1
        a[1] += 1
        n += 1
    elif x == count and sum % 2 == 1:
        sum += 1
        count += 1
        a[1] = 1
        a[0] = sum - 1    
        x = 1
        n += 1
    else:
        x += 1
        a[1] -= 1
        a[0] += 1
        n += 1
print(a[0],'/',a[1], sep = "")
    