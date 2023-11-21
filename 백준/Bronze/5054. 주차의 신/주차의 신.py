t = int(input())
for _ in range(t):
    s = input()
    arr=list(map(int, input().split()))
    print((max(arr)-min(arr))*2)