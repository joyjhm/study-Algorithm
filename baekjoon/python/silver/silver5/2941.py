croatia_word = input()
i = 0
alp_num = 0
while i <= len(croatia_word) - 1:
    if i == len(croatia_word) - 1:
        alp_num += 1
        i += 1
    else:
        if croatia_word[i] == 'c' and (croatia_word[i+1] == '=' or croatia_word[i+1] == '-'):
            i += 2
            alp_num += 1
        elif croatia_word[i] == 'd' and croatia_word[i+1] == '-':
            i += 2
            alp_num += 1
        elif croatia_word[i] == 'l' and croatia_word[i+1] == 'j':
            i += 2
            alp_num += 1
        elif croatia_word[i] == 'n' and croatia_word[i+1] == 'j':
            i += 2
            alp_num += 1
        elif croatia_word[i] == 's' and croatia_word[i+1] == '=':
            i += 2
            alp_num += 1
        elif croatia_word[i] == 'z' and croatia_word[i+1] == '=':
            i += 2
            alp_num += 1
            if i - 2 != 0:
                if croatia_word[i-3] == 'd':
                    alp_num -= 1
        else:
            alp_num += 1
            i += 1
print(alp_num)