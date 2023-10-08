from sys import stdin
t = int(stdin.readline())

for _ in range(t):
    n, m = map(int,stdin.readline().split())
    queue = [i for i in map(int,stdin.readline().split())]
    count = 0
    while True:
        if m != 0:
            if queue.index(max(queue)) != 0:
                x = queue.pop(0)
                queue.append(x)
                m -= 1
            else:
                queue.pop(0)
                m -= 1
                count += 1
        else:
            if queue.index(max(queue)) != m:
                x = queue.pop(0)
                queue.append(x)
                m = len(queue) - 1
            else:
                count += 1
                break
    print(count)