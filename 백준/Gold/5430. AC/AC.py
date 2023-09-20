import sys
T = int(sys.stdin.readline())
for _ in range(T):
    p = sys.stdin.readline().rstrip()
    n = int(sys.stdin.readline())
    s = sys.stdin.readline().rstrip()
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


