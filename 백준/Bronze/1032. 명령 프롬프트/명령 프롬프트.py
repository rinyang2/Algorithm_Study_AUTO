s=[input()for _ in range(int(input()))]
t=''
for i in range(len(s[0])):
    b=True
    temp = s[0][i]
    for a in s:
        if a[i]!=temp:
            b = False
            break
    if b:
        t+=temp
    else:
        t+='?'
print(t)