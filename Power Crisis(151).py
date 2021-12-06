def Josephus(n,m):                   #n個城鎮 每m個挑出一個出來 回傳最後被挑出的城鎮編號
    if n==1:
        return 0
    return ( Josephus(n-1,m)+m ) % n

while(1):
    n=int(input())
    if n==0:
        break
    for m in range(1,n+1):
        if( Josephus(n-1,m) + 1 == 12): #編號從0開始算 所以第13個城鎮編號為12
            print(m)
            break
