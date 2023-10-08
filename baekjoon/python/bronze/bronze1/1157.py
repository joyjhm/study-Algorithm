a = input()
a = a.upper()               # 65 ~ 90

alp = []

for s in range(65,91):
    alp.append(a.count(chr(s)))
    

max = 0
index = 0
for i in range(0,len(alp)): 
    if alp[i] > max:
        index = i
        max = alp[i]

count = 0

for i in range(len(alp)):
    if max == alp[i]:
       count += 1
    if count > 1:
        print('?')
        exit()

print(chr(65+index))