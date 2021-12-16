y1, m1, d1 = map(int,input().split())
y2, m2, d2 = map(int,input().split())

d_day=0
if y2 - y1 > 1000 or (y2 - y1 == 1000 and (m2 - m1 > 0 or (m2 - m1 == 0 and  d2 - d1 >= 0))):
    print('gg')
    exit()
    
while not(y1 == y2 and m1 == m2 and d1 == d2):
    d1 += 1
    if m1 == 2:
        if y1 % 4 == 0:
            if y1 % 100 == 0:
                if y1 % 400 == 0:
                    if d1 > 29:
                        m1 += 1
                        d1 = 1
                else:
                    if d1 > 28:
                        m1 += 1
                        d1 = 1
            else: 
                if d1 > 29:
                    m1 += 1
                    d1 = 1
        else: 
            if d1 > 28:
                m1 += 1
                d1 = 1
    elif m1 == 4 or m1 == 6 or m1 == 9 or m1 == 11:   
        if d1 > 30:
            m1 += 1
            d1 = 1
    else:
        if d1 > 31:
            m1 += 1
            d1 = 1    
        
    if m1 > 12:
        m1 = 1
        y1 += 1
    
    d_day += 1

print('D-',d_day, sep = '')


