t = int(input())

for _ in range(t):
    count = 0
    n = int(input())
    b = [1] * n
    c = []
    while b[0] <= 3:
        b[len(b) - 1] += 1
        for i in range(len(b)-1, 0, -1):
            if b[i] > 3:
                b[i] = 0
                b[i-1] += 1
        if sum(b) == n and max(b) <= 3:
            s = (list(filter(lambda x : x > 0,b)))
            if s not in c:
                c.append(s)
    print(len(c) + 1)
        