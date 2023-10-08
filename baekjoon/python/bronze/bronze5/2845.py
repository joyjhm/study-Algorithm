a =list(map(int, input().split()))
b =list(map(int, input().split()))

people = a[0] * a[1]

for i in range(0,5):
    print(b[i] - people, end =" ")