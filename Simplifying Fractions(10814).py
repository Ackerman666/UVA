def GCD(a,b):
    if b==0:
        return a
    return GCD(b,a%b)
n=int(input())
while(n):
    a,b=map(int,input().split("/"))
    tempa=a
    tempb=b
    if tempa<tempb:
        tempa,tempb=tempb,tempa
    gcd=GCD(tempa,tempb)
    a=a//gcd
    b=b//gcd
    print("%d / %d"%(a,b))
    n-=1
