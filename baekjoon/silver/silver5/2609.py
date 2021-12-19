a, b = map(int,input().split())

gcd = 0
def get_gcd(a,b):
    gcd = 0
    n = 1
    while n <= min(a,b):
        if a % n == 0 and b % n == 0:
            if n > gcd:
                gcd = n
        n += 1
    return gcd
gcd = get_gcd(a,b)
print(gcd)

lcm = 1
while True: 
    a = a // gcd
    b = b // gcd
    if gcd != 1:
        lcm *= gcd
        gcd = get_gcd(a,b)
    else:
        lcm *= a * b
        break
    
print(lcm)
