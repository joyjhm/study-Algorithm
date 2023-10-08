import math

a = list(map(int, input().split()))

if a[0] - a[2] == 0:
    gradient1 = 1000000
else:
    gradient1 = (a[1] - a[3]) / (a[0] - a[2])

if a[0] - a[4] == 0:
    gradient2 = 1000000
else:
    gradient2 = (a[1] - a[5]) / (a[0] - a[4])

if gradient1  == gradient2:
    print(-1.0)
    exit()
else:
   x = math.sqrt(pow(a[0] - a[4],2) + pow(a[1] - a[5], 2)) + math.sqrt(pow(a[0] - a[2],2) + pow(a[1] - a[3], 2))         # 1 
   y = math.sqrt(pow(a[0] - a[2],2) + pow(a[1] - a[3], 2)) + math.sqrt(pow(a[2] - a[4],2) + pow(a[3] - a[5], 2))         # 2
   z = math.sqrt(pow(a[0] - a[4],2) + pow(a[1] - a[5], 2)) + math.sqrt(pow(a[2] - a[4],2) + pow(a[3] - a[5], 2))         # 3
           
max = max(x, y, z)
min = min(x, y, z)
print(2 * (max - min))