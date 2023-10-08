n = int(input())

result = 0
rec2_2 = 0
rec2_1 = n
x = 1

while  rec2_2 * 2 <= n:
    a = 1
    b = 1
    for i in range(0, rec2_2):
       a *=  rec2_2 + rec2_1 - i
       b *= i + 1
    
    result = result + ((a // b) * pow(2, rec2_2))
    rec2_2 += 1
    rec2_1 = n - rec2_2 * 2
    
print(result % 10007)
    
    