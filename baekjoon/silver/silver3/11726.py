n = int(input())
result = 1
a = 1
b = 2
x = 3

if n == 1:
    result = 1
elif n == 2:
    result = 2
    

while x <= n and x > 2:
    result = a + b
    a = b
    b = result
    x += 1

result = result % 10007
print(result)