n = int(input())
factorial = 1
count = 0
for i in range(1, n+1):
    factorial *= i

while factorial % 10 == 0:
    count += 1
    factorial = factorial // 10

print(count)
