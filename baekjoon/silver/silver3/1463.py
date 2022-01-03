n = int(input())
count = 1
min = 100
def makeOne(n, count):
    global min
    if n <= 3:
        if min > count:
            min = count

    else:
        if n % 3 == 0 and n % 2 == 0:
            makeOne(n // 3, count + 1)
            makeOne(n // 2, count + 1)
        elif n % 3 == 0 and n % 2 == 1:
            makeOne(n // 3, count + 1)
            makeOne((n - 1) // 2, count + 2)    
        elif n % 3 == 1 and  n % 2 == 0:
            makeOne(n // 2, count + 1)
            makeOne((n - 1) // 3, count + 2)
        elif n % 3 == 2 and  n % 2 == 0:
            makeOne(n // 2, count + 1)
            makeOne((n - 2) // 3, count + 3)
        else:
            makeOne(n - 1, count + 1)
            
if n == 1:
    print(0)
    exit()

makeOne(n,count)
print(min)