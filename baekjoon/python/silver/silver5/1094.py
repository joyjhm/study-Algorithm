want_stick = int(input())
stick = 0
count = 0

while want_stick != stick:
    mul = 1
    while  mul * 2 + stick <= want_stick:
        mul *= 2
    stick += mul
    count += 1

print(count)
