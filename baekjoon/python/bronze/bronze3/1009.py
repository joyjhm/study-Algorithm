test = int(input())

for i in range(0,test):
    a , b = list(map(str, input().split()))
    c = int(b) % 4
    if c == 0:
        c = 4
    data = pow(int(a[len(a)-1]), c)
    answer = data % 10
    if answer == 0:
        answer = 10
    print(answer)
    