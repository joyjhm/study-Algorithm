m = int(input())
n = int(input())
prime_number = []
count = m
while count >= m and count <= n:
    is_primenumber = True
    if count == 1:
        is_primenumber = False
    for i in range(2, count):
        if count % i == 0:
            is_primenumber = False
            break
    if is_primenumber:
        prime_number.append(count)
    count += 1
if prime_number:
    print(sum(prime_number))
    print(min(prime_number))
else:
    print(-1)