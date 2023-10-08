num = int(input())
names = []
for i in range(0,num):
    names.append(input())
play_game = False
for i in range(97,123):
    count = 0
    for name in names:
        if name[0] == chr(i):
            count += 1
    if count >= 5:
        print(chr(i), end="")
        play_game = True

if play_game == False:
    print('PREDAJA')        
        