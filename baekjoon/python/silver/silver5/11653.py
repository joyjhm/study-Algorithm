n = int(input())

count = 2
while n != 1:
    while n % count == 0:
        n = n // count
        print(count)
    count += 1