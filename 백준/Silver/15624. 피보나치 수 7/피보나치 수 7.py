arr=[0]*1000001
arr[0]=0
arr[1]=1
arr[2]=1
for i in range(3,1000001):
    arr[i]=(arr[i-1]+arr[i-2])%1000000007
print(arr[int(input())])