import sys
inputvalue = list(map(int,sys.stdin.readline().rstrip().split(" ")))

a = dict()
#그래프 만들기 
def makegraph(num1,num2):
    a[num1] = {num2} | a[num1] if num1 in a else {num2}
    a[num2] = {num1} | a[num2] if num2 in a else {num1}
    
count = inputvalue[1]

#반복되는 입력 받기 
for i in range(count):
    value = list(map(int, input().split(" ")))
    makegraph(value[0],value[1])


# dfs 만들기

def dfs(graph,start):
    visited = []
    vertex = [start,]

    while vertex:
        point = vertex.pop()
        if point not in visited:
            visited.append(point)
            bb = list(graph[point] - set(visited))#역순으로만들기/ 작은걸 먼저 출력할것임 
            bb.sort(reverse = True)
            vertex.extend(bb)
    return visited



def bfs(graph,start):
    visited = []
    vertex = [start,]

    while vertex:
        point = vertex.pop(0)
        if point not in visited:
            visited.append(point)
            cc = list(graph[point] - set(visited))
            cc.sort()
            vertex.extend(cc)
    return visited



abcd = dfs(a,inputvalue[2])
efgh = bfs(a,inputvalue[2])

r=''
for s in abcd:
    r+=str(s)+' '
print(r.rstrip())


g=''
for s in efgh:
    g+=str(s)+' '
print(g.rstrip())
