a =list(map(int, input().split()))
answer = [1, 1, 2, 2, 2, 8]

b = 0
for i in answer:
    print(i - a[b], end = " ")
    b += 1

