arr=list(map(int, input().split()))
print(0 if arr[0]*arr[1]<arr[2] else arr[0]*arr[1]-arr[2])