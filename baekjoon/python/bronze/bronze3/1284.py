while(True):
    a = input()
    sum = 0;
    if a == '0':
        break
    
    for i in a:
        if i == '1':
            sum += 3
        elif i == '0':
            sum += 5
        else:
            sum += 4
    sum += 1
    print(sum)
