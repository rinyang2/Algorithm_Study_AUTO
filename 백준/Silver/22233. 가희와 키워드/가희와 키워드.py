import sys
N,M=map(int, sys.stdin.readline().split())
dic = set(sys.stdin.readline().rstrip() for _ in range(N))
cnt = 0
for _ in range(M):
    arr=list(sys.stdin.readline().rstrip().split(','))
    for a in arr:
        if a in dic:
            cnt+=1
            dic.remove(a)
    print(N-cnt)
