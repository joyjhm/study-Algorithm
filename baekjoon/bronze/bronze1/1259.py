
while True:
    Palindrome = True
    a = input()
    
    if a == '0':
        exit()
    else:
        count = 0
        if len(a) % 2 == 0:
            x = len(a) // 2 - 1
            while x - count >= 0:
                if a[x - count] == a[x + count + 1]:
                    Palindrome = True
                    count += 1
                else:
                    Palindrome = False
                    print('no')
                    break
            
        else:
            count += 1
            y = len(a) // 2 
            while y - count >= 0:
                if a[y - count] == a[y + count]:
                        Palindrome = True
                        count += 1
                else:
                    Palindrome = False
                    print('no')
                    break
    if Palindrome == True:
        print('yes')
    
        