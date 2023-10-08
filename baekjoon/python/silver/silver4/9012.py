from sys import stdin
T = int(input())

for i in range(T):
    vps = []
    breaker = False
    s = stdin.readline().strip()
    for j in range(len(s)):
        if s[j] == '(':
            vps.append(')')
        elif s[j] == ')':
            if vps:
                vps.pop()
            else:
                breaker = True
                break
    if vps:
        print("NO")
    else:
        if breaker:
            print("NO")
        else:
            print('YES')
    
         