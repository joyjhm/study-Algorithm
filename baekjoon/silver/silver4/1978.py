from sys import stdin
n = int(input())
numbers = list(map(int,stdin.readline().split()))

count = 0
for number in numbers:
    is_prime = True
    
    for i in range(2,number):
        if number % i == 0:
            is_prime = False
            break
    if number == 1:
        is_prime = False
    
    if is_prime:
        count += 1
        
print(count)


