from sys import stdin
k, n = map(int, stdin.readline().split())
line = [int(stdin.readline()) for _ in range(k)]

left, right = 1, max(line)



while left <= right:
    mid = (left + right) // 2
    count = 0
    for i in line:
        count += (i // mid)
    
    if n <= count:
        left = mid + 1
    else:
        right = mid - 1
print(right)