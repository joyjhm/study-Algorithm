from sys import stdin
n = int(stdin.readline())
numbers = []
count_number = [0] * 8001
a = []

for i in range(n):
    x = int(stdin.readline()) 
    numbers.append(x)
    count_number[x] += 1
numbers = sorted(numbers)

sum = sum(numbers)                           # 산술 평균
print(int(round(sum / n, 0)))

print(numbers[(len(numbers)-1)//2])          # 중앙값

max = max(count_number)                      # 최빈값
if count_number.count(max) > 1:
    for i in range(-4000,4001):
        if max == count_number[i]:
            a.append(i)
    print(a[1])
else:    
    index = count_number.index(max)
    if index > 4000:
        index = -(8001 - index)
    print(index)

print(numbers[len(numbers)-1] -numbers[0])   # 범위