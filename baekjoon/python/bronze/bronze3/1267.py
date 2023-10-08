call_count = int(input())
call = list(map(int, input().split()))
m, y = 0, 0

for i in call:
    if i >= 30:
        y += (i // 30) * 10 + 10
    else:
        y += 10
    
    if i >= 60:
        m += (i // 60) * 15 + 15
    else:
        m += 15

if y == m:
    print("Y M", y)
elif y < m:
    print("Y", y)
else:
    print("M", m)
            
