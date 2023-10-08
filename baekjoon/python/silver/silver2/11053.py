from sys import stdin

n = int(stdin.readline())
a = list(map(int, stdin.readline().split()))
a.insert(0,0)
sol = [0 for i in range(n + 1)]

for i in range(1, n + 1):
    for j in range(i):
        if a[i] > a[j]:
            if sol[i] < sol[j] + 1:
                sol[i] = sol[j] + 1

print(max(sol))


        