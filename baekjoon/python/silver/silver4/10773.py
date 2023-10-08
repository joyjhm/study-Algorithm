from sys import stdin
K = int(input())
stack = []
for i in range(K):
    n = int(stdin.readline().strip())
    if  n == 0:
        stack.pop()
    else:
        stack.append(n)

print(sum(stack))