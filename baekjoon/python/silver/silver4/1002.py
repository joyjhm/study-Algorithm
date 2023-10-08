from sys import stdin
import math
T = int(input())

for i in range(T):
    x1, y1, r1, x2, y2, r2 = map(int,stdin.readline().split())
    d = math.sqrt(pow(x1- x2, 2) + pow(y1-y2, 2))
    
    if x1 == x2 and y1 == y2 and r1 == r2:
        print(-1)
    else:
        if r1 + r2 < d:             # 외부에서 만나지 않는다
            print(0)
        elif r1 + r2 == d:          # 외접
            print(1)
        elif max(r1, r2)-min(r1, r2) == d:  # 내접
            print(1)
        elif max(r1, r2)-min(r1, r2) < d and r1 + r2 > d:    # 두 점에서 만난다.
            print(2)
        elif max(r1, r2)-min(r1, r2) > d:                    # 내부에서 만나지 않는다.
            print(0)
        