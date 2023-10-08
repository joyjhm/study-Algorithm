a =list(map(int, input().split()))

if a[0] == 1:
    print(a[1])
else:
    print(a[0] * (a[1] - 1) + 1)
    