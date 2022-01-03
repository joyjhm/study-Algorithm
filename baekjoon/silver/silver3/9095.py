def factorial(n):
    if n == 1 or n == 0:
        return 1
    
    return n * factorial(n - 1)

def addOneTwoThree(x, i, n):    
    global b
    global count
    
    if sum(b) == n:
        count = count + (factorial(len(b)) // (factorial(b.count(1)) * factorial(b.count(2)) * factorial(b.count(3))))
        return
    if x - i >= 0 and sum(b) != n:
        b.append(i)
        for j in range(1, i + 1):
            addOneTwoThree(x - i, j, n)
            if sum(b) == n:
                break
    if len(b) > 1:
        b.pop()
             
t = int(input())

for _ in range(t):
    count = 0
    n = int(input())
    for i in range(1, 4):
        b = []
        addOneTwoThree(n,i,n)
    print(count)
        