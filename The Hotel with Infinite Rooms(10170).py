while(1):
    try:
        s,d=map(int,input().split())
        a=1
        b=2*s-1
        c=-2*d
        n=(-b+pow(b*b-4*a*c,0.5))/(2*a)
        n=int(n)
        if n*n+(2*s-1)*n-2*d != 0:
            n=n+1
        print(s+(n-1))
    except EOFError:
        break
