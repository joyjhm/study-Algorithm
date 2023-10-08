n = input()
s = []
for i in n:
    s.append(i)

for i in range(0,len(n)-1):
    for j in range(i+1, len(n)):
        if s[j] > s[i]:
            temp = s[j]
            s[j] = s[i]
            s[i] = temp
            
print(s)
