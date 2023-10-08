n, m = map(int,input().split())
p = []
def sol(m, index):
    if m == 0:
        for j in p:
            print(j, end= " ")
        print()
    else:
        for i in range(index, n + 1):
            if i in p:
                continue
            p.append(i)
            sol(m - 1, i + 1)
            p.pop()

sol(m, 1)