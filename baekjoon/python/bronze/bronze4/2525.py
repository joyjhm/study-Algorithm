a, b = (map(int, input().split()))
c = int(input())

hour_add = 0
min = b + c  
if min >= 60:
    while(min >= 60):
         min -= 60
         hour_add += 1
hour = a
hour = hour + hour_add
if hour >= 24:
    while(hour >= 24):
        hour -= 24
        
print(hour, min)
           

    