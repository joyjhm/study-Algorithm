n = int(input())

count = 0
for i in range(n):
    word = input()
    b = True
    for s in word:
        x, y = 0, 0        
        while x != -1:
            x = word.find(s, y)
            if y == 0 or y == x or x == -1:
                pass
            else:
                b = False
            y = x + 1
    if b:
        count += 1
print(count)           
                  
        
