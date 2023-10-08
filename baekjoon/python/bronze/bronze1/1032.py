a = int(input())

str = []
for i in range(0,a):
    str.append(input())

result = []
for i in range(len(str[0])):
    s = True
    for j in range(len(str)-1):
        if  str[j][i] != str[j + 1][i]:
                result.append('?')
                s = False
                break
    if s:
        result.append(str[0][i])

print("".join(result))
