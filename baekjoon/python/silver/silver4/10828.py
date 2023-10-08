from sys import stdin

n = int(input())
numbers = []
instruction = ["push ", "pop", "size", "empty", "top"]
for i in range(n):
    s = stdin.readline().strip()
    if "push" in s:
        s = s.replace("push ", "")
        numbers.append(int(s))
    if s == "pop":
        if numbers:
            print(numbers.pop())
        else:
            print(-1)
    elif s == "size":
        print(len(numbers))
    elif s == "empty":
        if numbers:
            print(0)
        else:
            print(1)
    elif s == "top":
        if numbers:
            print(numbers[len(numbers)-1])
        else:
            print(-1)

    
    

