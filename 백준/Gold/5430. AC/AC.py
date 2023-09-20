T = int(input())
for _ in range(T):
    p = input()
    n = int(input())
    s = input()
    if s == "[]":
        q=[]
    else:
        q = list(s[1:-1].split(','))
    b = True
    l = 0
    r = 0
    for char in p:
        if char == 'R':
            b = not b
        else:
            if b:
                l+=1
            else:
                r+=1
    ans = q[l:len(q)-r]
    if not b:
        ans = ans[::-1]
    if l+r > len(q):
        print("error")
    else:
        print("["+','.join(ans)+']')
    #print("error" if len(ans)==0 else (ans if b else ans[::-1]), sep='')

