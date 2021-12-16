a =list(map(int, input().split()))
sum = 0
for i in range(0,5):
    sum += a[i] * a[i]
result = sum % 10
print(result)

