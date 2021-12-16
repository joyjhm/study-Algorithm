
while True:
    str = input()
    if str == '#':
        break
    str = str.lower()
    sum = 0
    sum += str.count('a')
    sum += str.count('e')
    sum += str.count('i')
    sum += str.count('o')
    sum += str.count('u')
    print(sum)
     