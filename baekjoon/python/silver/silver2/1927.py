from sys import stdin
n = int(stdin.readline())
heap = [0]

def addMinHeap():
    a = len(heap) - 1
    while a > 1:
        if heap[a] < heap[a // 2]:
            heap[a], heap[a // 2] = heap[a // 2], heap[a]
        a = a // 2

def popMinHeap():
    a = len(heap) - 1
    b = 1
    heap[a], heap[1] = heap[1], heap[a]
    print(heap.pop())
    
    while b * 2 <= len(heap) - 1:
        if len(heap) - 1 < (b * 2)  + 1:
            if heap[b * 2] < heap[b]:
                heap[b], heap[b * 2] = heap[b * 2] , heap[b]
                b *= 2
            else:
                break
        else:
            if heap[b] < heap[b * 2] and heap[b] < heap[(b * 2) + 1]:
                break
            else:
                if heap[b * 2] < heap[(b * 2)  + 1]:
                    heap[b], heap[b * 2] = heap[b * 2] , heap[b]
                    b *= 2
                else :
                    heap[b], heap[(b * 2) + 1] = heap[(b * 2) + 1] , heap[b]
                    b = (b * 2) + 1

    
for _ in range(n):
    x = int(stdin.readline())
    if x == 0:    
        if len(heap) != 1:
            popMinHeap()
        else:
            print(0)
    else:
        heap.append(x)
        addMinHeap()
