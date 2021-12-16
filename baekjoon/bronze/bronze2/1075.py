n = int(input())
f = int(input())

x = n % f                   # x = 나머지
y = n % 100                 # y = n의 십의자리수와 일의자리수 


if y - x  < 0:
    result = f - x + y
    print('{:02d}'.format(result))
else:
    result = y - x 
    while result >= f:
         result = result - f
    print('{:02d}'.format(result))
    
        