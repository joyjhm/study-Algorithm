from sys import stdin
n = int(input())
deque = []
for i in range(n):
    s = stdin.readline().strip()
    
    if "push_back" in s:
        s = s.replace("push_back ", "")
        deque.append(int(s))
    elif "push_front" in s:
        s = s.replace("push_front ", "")
        deque.insert(0,int(s))
    if s == "pop_front":
        if deque:
            print(deque.pop(0))
        else:
            print(-1)
    elif s == "pop_back":
        if deque:
            print(deque.pop())
        else:
            print(-1)
    elif s == "size":
        print(len(deque))
    elif s == "empty":
        if deque:
            print(0)
        else:
            print(1)
    elif s == "front":
        if deque:
            print(deque[0])
        else:
            print(-1)
    elif s == "back":
        if deque:
            print(deque[len(deque) - 1])
        else:
            print(-1)