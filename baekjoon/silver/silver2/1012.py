from sys import stdin
t = int(stdin.readline())

for _ in range(t):
    m, n, k = map(int, stdin.readline().split())
    queue = []                                  # 인접해 있는 배추들을 리스트별로 나타냄  
    crop = []   
    for __ in range(k):
        y, x = map(int, stdin.readline().split())
        crop.append((x,y))
    crop = sorted(crop)                         # 순서대로 queue에 넣기 위해서 정렬
    print(crop)
    for i in range(len(crop)):
        x, y = crop[i]
        

    print(len(queue))