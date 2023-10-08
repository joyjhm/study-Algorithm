import sys

n = int(input())
words = []

for i in range(n):
    s = sys.stdin.readline().strip()
    if s not in words:
        words.append(s)
x = len(words)
count = 0
while count < x :
    min = 51
    for str in words:
        if len(str) < min:
            min = len(str)
    same_len_words = []
    
    for a in range(len(words)):
        if len(words[a]) == min:
            same_len_words.append(words[a])
            words[a] = 'a' * 51
            count += 1
            
    
                   
    same_len_words = sorted(same_len_words)
    for word in same_len_words:
        print(word)
