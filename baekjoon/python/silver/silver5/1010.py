num  = int(input())

for i in range(num):
    a, b = map(int,input().split())
    n = 1
    m = 1
    if a == 1:
        print(b)
    elif a == b:
        print(1)
    else:
        for i in range(a):
            n *= b - i
        for j in range(1, a + 1):
            m *= j
        
        print(n // m)
    
        