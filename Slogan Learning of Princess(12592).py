N = int(input())
dic = {}
for i in range(0,N):
    key = input()
    value = input()
    dic[key] = value
Q = int(input())
for i in range(0,Q):
    key = input()
    print(dic[key])
