n = input()
cycle = 0
if int(n) < 10:
    n = '0' + n
a = n
    
while n != a or cycle == 0:
    b = int(a[0]) + int(a[1])
    a = a[1] + str(b % 10)
    cycle += 1

print(cycle)
