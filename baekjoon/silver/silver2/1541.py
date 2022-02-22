s = input().split('-')

result = 0
for i in s[0].split('+'):
    result += int(i)
for i in range(1, len(s)):
    for j in s[i].split('+'):
        result -= int(j)

print(result)
