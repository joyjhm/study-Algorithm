from sys import stdin
n, m = map(int, stdin.readline().split())
tree = list(map(int,stdin.readline().split()))
tree = sorted(tree)
h = max(tree)
count = 0
s = 0
while s < m:
    s += count 
    while True:
        if tree:
            if tree[len(tree) - 1] == h:
                tree.pop()
                count += 1  
            else:
                break
        else:
            break
    h -= 1
        
print(h + 1)
    
