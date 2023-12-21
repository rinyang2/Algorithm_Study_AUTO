n=int(input())
arr=list(map(int,input().split()))
arr=sorted([[arr[i],i]for i in range(len(arr))])
arr=[[arr[i], i]for i in range(len(arr))]
arr.sort(key=lambda x:x[0][1])
print(*[x[1] for x in arr])