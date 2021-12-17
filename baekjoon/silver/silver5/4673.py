n = 1
s = [i == False for i in range(0,10001)]
s[0] = True
while n <= 10000:
    result = n
    sum = 0 
    for i in str(n):
        sum += int(i)
    result += sum
    if result <= 10000:    
        s[result] = True
    n += 1
    
for j in range(1,10001):
    if not s[j]:
        print(j) 
    
        
       