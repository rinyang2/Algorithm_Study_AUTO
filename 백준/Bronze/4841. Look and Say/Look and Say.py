for _ in range(int(input())):
    s=input()
    cnt=0
    now=s[0]
    ans=''
    for i in s:
        if now==i:
            cnt+=1
        else:
            ans+=str(cnt)+now
            now = i
            cnt = 1
    ans+=str(cnt)+now
    print(ans)