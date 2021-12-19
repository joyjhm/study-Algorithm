import sys
n = int(input())
member = []
for i in range(n):
    a, b = sys.stdin.readline().split()
    member.append((int(a), i, b))
    
member = sorted(member)

for a,b,c in member:
    print(a,c, sep = " ")