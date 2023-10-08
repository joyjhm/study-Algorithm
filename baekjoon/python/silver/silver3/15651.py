n, m = map(int,input().split())
p = []
def sol(m):
    if m == 0:
        for j in p:
            print(j, end= " ")
        print()
    else:
        for i in range(1, n + 1):
            p.append(i)
            sol(m - 1)
            p.pop()

sol(m)