import sys
alph = 'abcdefghijklmnopqrstuvwxyz'
N,K = map(int, sys.stdin.readline().split())

dic = {}
for i in alph:
    dic[i] = False
for i in 'antic':
    dic[i] = True

ans = 0
arr=[]
for _ in range(N):
    arr.append(sys.stdin.readline().rstrip())

def rec(level, last):
    global ans
    if level>=K-5:
        temp = 0
        for word in arr:
            b = True
            for letter in word:
                if not dic[letter]:
                    b = False
                    break
            if b:
                temp += 1
        ans = max(temp, ans)
        return
    for i in alph:
        if not dic[i] and i>last:
            dic[i] = True
            rec(level+1, i)
            dic[i] = False

if K<5:
    print(0)
else:
    rec(0,'a')
    print(ans)