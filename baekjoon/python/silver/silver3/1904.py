import sys
n = int(sys.stdin.readline())
result = [0] * 1000001
result[1] = 1
result[2] = 2

for i in range(3,n+1):
    result[i] = (result[i -1] + result[i - 2]) % 15746

print(result[n])



