import sys
n = int(sys.stdin.readline())
numbers = [0] * 10001
for i in range(n):
    a = int(sys.stdin.readline())
    numbers[a] += 1

for i in range(10001):
    if numbers[i] != 0:
        for j in range(numbers[i]):
            print(i)    



