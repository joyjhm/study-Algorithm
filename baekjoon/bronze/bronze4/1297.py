a =list(map(int, input().split()))

x = pow(a[1],2) + pow(a[2],2)
z = pow(a[0],2) / x
y = z ** (1/2)
print(int(y * a[1]), int(y * a[2])) 

