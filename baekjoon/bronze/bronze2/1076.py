a = input()
b = input()
c = input()

dic = {
    'black' : '0',
    'brown' : '1',
    'red'   : '2',
    'orange': '3',
    'yellow': '4',
    'green' : '5',
    'blue'  : '6',
    'violet': '7',
    'grey'  : '8',
    'white' : '9'
}

d = dic[a] + dic[b]
result = int(d) * pow(10, int(dic[c])) 
print(result) 