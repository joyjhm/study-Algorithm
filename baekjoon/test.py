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
    count = 0
    while crop:
        if not queue:
            x, y = crop.pop(0)
            count += 1
        else:
            x, y = queue.pop(0)
        if (x + 1, y) in crop:
            queue.append(crop.pop(crop.index((x + 1, y))))
        if (x, y + 1) in crop:
            queue.append(crop.pop(crop.index((x, y + 1))))
        if (x - 1, y) in crop:
            queue.append(crop.pop(crop.index((x - 1, y))))
        if (x, y - 1) in crop:
            queue.append(crop.pop(crop.index((x, y - 1))))
    print(count)