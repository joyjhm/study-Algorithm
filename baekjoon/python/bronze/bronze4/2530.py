a, b, c  = (map(int, input().split()))
d = int(input())

min_add = 0
hour_add = 0
sec = c + d  
if sec >= 60:
    while(sec >= 60):
         sec -= 60
         min_add += 1

min = b + min_add
if min >= 60:
    while(min >= 60):
        min -= 60
        hour_add += 1 
hour = a
hour = hour + hour_add
if hour >= 24:
    while(hour >= 24):
        hour -= 24
        
print(hour, min, sec)
