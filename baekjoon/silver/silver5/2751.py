from sys import stdin

N = int(input())
nums = [int(stdin.readline().strip()) for i in range(N)]
nums.sort()

for i in nums:
    print(i)

