t = int(input())
for _ in range(t):
    n = int(input())
    count0_3 = 1
    count0_4 = 2
    count1_3 = 2
    count1_4 = 3
    if n == 0:
        print(1, 0)
    elif n == 1:
        print(0, 1)
    elif n == 2:
        print(1, 1)
    elif n == 3:
        print(1, 2)
    elif n == 4:
        print(2, 3)
    else:
        x = 5
        count0_next = 0
        count1_next = 0
        while x <= n:
            count0_next = count0_3 + count0_4
            count0_3 = count0_4
            count0_4 = count0_next
            count1_next = count1_3 + count1_4
            count1_3 = count1_4
            count1_4 = count1_next
            x += 1
        print(count0_next, count1_next)

