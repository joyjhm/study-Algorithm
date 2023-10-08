import sys
n = int(input())
meeting = []
for i in range(n):
    a = tuple(map(int, sys.stdin.readline().split()))
    meeting.append(a)
meeting = sorted(meeting)
meeting = sorted(meeting , key = lambda x : x[1])
end = 0
count = 0
for s, e in meeting:
    if s >= end:
        end = e
        count += 1
print(count)
