n = int(input())

num1 = 1
num2 = 1
x = 3
result = 1
while x <= n and n > 2:
    result = num1 + num2
    num1 = num2
    num2 = result
    x += 1 

print(result)