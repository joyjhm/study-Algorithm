from sys import stdin
dic = []
def sol(n):
    if len(dic) == 6:
        for j in dic:
            print(j, end = ' ')
        print()
    else:
        for i in range(n, s[0] + 1):
            if s[i] in dic:
                continue
            dic.append(s[i])
            sol(i + 1)
            dic.pop()  
while True:
    s = list(map(int, stdin.readline().split()))
    if s[0] == 0:
        break
    sol(1)
    print()