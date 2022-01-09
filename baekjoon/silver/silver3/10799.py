from sys import stdin
s = stdin.readline()
stick = 0
laser = 0
piece = 0
i = 0
while i < len(s) - 1:
    if s[i] == '(' and s[i + 1] == ')':
        if stick != 0:
            piece += stick
        i += 2
    elif s[i] == '(':
        stick += 1
        piece += 1
        i += 1
    elif s[i] == ')':
        stick -= 1
        i += 1

print(piece)
        