# 출처: https://wook-2124.tistory.com/468

n = int(input())

word = []
for i in range(n):
    word.append(input())

set_word = list(set(word))

sort_word = []
for i in set_word:
    sort_word.append((len(i),i))
    
result = sorted(sort_word)

print(result)

