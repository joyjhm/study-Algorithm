from sys import stdin

n = int(input())
queue = []
for i in range(n):
    s = stdin.readline().strip()
    if "push" in s:
        s = s.replace("push ", "")
        queue.append(int(s))
    if s == "pop":
        if queue:
            print(queue.pop(0))
        else:
            print(-1)
    elif s == "size":
        print(len(queue))
    elif s == "empty":
        if queue:
            print(0)
        else:
            print(1)
    elif s == "front":
        if queue:
            print(queue[0])
        else:
            print(-1)
    elif s == "back":
        if queue:
            print(queue[len(queue)-1])
        else:
            print(-1)
        