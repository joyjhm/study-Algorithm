a, b = map(int,input().split())

def get_gcd(a,b):
    while b != 0:
       r = a % b
       a = b
       b = r
    return a
gcd = get_gcd(a,b)
print(gcd)

lcd = a * b // gcd
print(lcd)