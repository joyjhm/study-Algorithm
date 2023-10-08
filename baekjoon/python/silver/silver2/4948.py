from sys import stdin
T = 246913
prime = [1] * T
prime[1] = 0
for i in range(2, int(T ** (0.5) + 1)):
    if prime[i]:
        for j in range(i * 2, T, i):
            prime[j] = 0

while True:
    count = 0
    n = int(stdin.readline())
    if n == 0:
        break
    for i in range(n + 1, 2 * n + 1):
        if prime[i]:
            count += 1
    print(count)
    