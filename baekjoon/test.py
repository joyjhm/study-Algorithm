def ranked(a):
    count = 1
    while min(a) != 51:
        rank = a
        x = min(a)
        y = a.index(min(a))
        rank[y] = count
        a[y] = 51
        count2 = 1
        while True:
            if x == min(a):
                rank[a.index(min(a))] = count
                a[a.index(min(a))] = 51
                count2 += 1
            else:
                count += count2
                break
    
