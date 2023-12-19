from collections import deque

# Class to represent a box
class Box:
    def __init__(self, c, idx):
        self.c = c
        self.idx = idx

    # Custom comparison for sorting in descending order
    def __lt__(self, other):
        return self.c > other.c

# Input
N = int(input())
s = input()
v = [[] for _ in range(N + 1)]

for _ in range(N - 1):
    a, b = map(int, input().split())
    v[a].append(b)
    v[b].append(a)

visited = [0] * (N + 1)
ans = []

# Initialize
ans.append(s[0])
q = deque([(1, 1)])
visited[1] = 1

while q:
    # Pair (node, depth)
    now = q.popleft()
    vp = [now]

    # Pop all nodes that have the same depth and store in list "vp"
    while q and q[0][1] == now[1]:
        vp.append(q.popleft())

    # Push every child node to list temp and sort
    temp = []
    for a in vp:
        for b in v[a[0]]:
            if visited[b] == 0:
                temp.append(Box(s[b - 1], b))
                visited[b] = 1

    temp.sort()

    # If there is no child, continue
    if not temp:
        continue

    # Add the biggest child to the answer
    ans.append(temp[0].c)

    # Push every node that has the same child value
    for a in temp:
        if a.c == temp[0].c:
            q.append((a.idx, now[1] + 1))

# Output
print(''.join(ans))
