N, m, M, T, R = map(int, input().split())

x = m
min = 0
count = 0

if m + T > M:
    print(-1)
    count = N

while count < N:
    if x + T <= M:
        x +=  T
        count += 1
        min += 1
        if count == N:
            print(min)
        continue
    else:
        while x + T > M:
            x -= R
            if x < m:
                x = m
            min += 1
            
    

  

        

