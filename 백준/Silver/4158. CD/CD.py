import sys
while(True):
    N, M = map(int, input().split())
    if N==0 and M==0:
        break
    s1 = set()
    s2 = set()
    for _ in range(N):
        s1.add(sys.stdin.readline())
    cnt = 0
    for _ in range(N):
        temp = sys.stdin.readline()
        if temp in s1:
            if temp not in s2:
                cnt+=1
                s2.add(temp)
    print(cnt)