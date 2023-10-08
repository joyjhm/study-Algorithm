while True:
    
    a = list(map(int, input().split()))
    if a[0] == 0:
        break
    branch = 1
    for i in range(1, 2 * a[0] + 1, 2):
        branch *= a[i]
        branch -= a[i+1]
    print(branch)