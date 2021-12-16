a =list(map(int, input().split()))

x = a[2]-a[1]
if x > 0:
    print((a[0] // x) + 1)
else:
    print(-1)
     