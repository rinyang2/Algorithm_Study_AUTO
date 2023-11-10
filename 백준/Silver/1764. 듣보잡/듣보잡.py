import sys
N,M = map(int, sys.stdin.readline().split())
n = []
m = []
for i in range(N):
    n.append(sys.stdin.readline().rstrip())
for i in range(M):
    m.append(sys.stdin.readline().rstrip())
s = list(set(n)&set(m))
s.sort()
print(len(s))
for i in s:
    print(i)