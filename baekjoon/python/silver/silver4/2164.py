import sys
n = int(sys.stdin.readline())
numbers = [i for i in range(1,n+1)]

while len(numbers) > 3:
    if len(numbers) % 2 == 0:
        numbers = numbers[1::2]
    else:
        numbers = numbers[3::2] +numbers[1:2]

if len(numbers) == 1:
    print(1)
else:
    print(numbers[1])

