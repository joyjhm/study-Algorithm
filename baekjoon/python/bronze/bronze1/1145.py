def lcd(i, j):
    g1 = i
    g2 = j
    g4 = 1
    while(True):
        g3 = math.gcd(g1, g2)
        if g3 != 1:
            g1 = g1 // g3
            g2 = g2 // g3
            g4 *= g3
        else :
            g4 *= g1 * g2
            break
    return g4

a = list(map(int,input().split()))
import math
min = 1000000

for i in range(3):
    for j in range(i+1,4):
        for k in range(j+1,5):
          x = lcd(lcd(a[i], a[j]),a[k])
          if x < min:
              min = x

print(min)

     