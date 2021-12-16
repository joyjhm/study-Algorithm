from sys import stdin

for i in range(0,3):
    
    count = int(stdin.readline())
    a = [int(stdin.readline()) for i in range(count)]
    
    if sum(a) > 0:
        print('+')
    elif sum(a) < 0:
        print('-')
    else:
        print(0)
    