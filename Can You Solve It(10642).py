n=int(input())
case=1
while(n):
    x1 , y1 , x2 , y2 = map(int , input().split())
    line1 = (x1+y1)                   #點當前所在的線
    line2 = (x2+y2)
    ans=0
    if line1 != line2:
        ans+=y1                   #先讓回歸到x軸
        ans+=1                    #讓點到下一條線的起始點
        line1+=1                  #點當前所在的線
        
        ans+= (line1+(line2-1)) * (line2-line1) //2 + (line2-line1) #計算到目標線的起始點 所要花費的steps
      
        y1=line2                #讓點到目標線的起始位置
    ans+=(y1-y2)
    print("Case %d: %d"%(case,ans))
    case+=1
    n-=1
