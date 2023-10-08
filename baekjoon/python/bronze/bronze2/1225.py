a, b = map(str, input().split())

x = 0
y = 0
for i in a:
    x += int(i)
for i in b:
    y += int(i)
print(x * y)
