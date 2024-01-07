arr=[1]*68
arr[2]=2
arr[3]=4
for i in range(4,68):
    arr[i] = arr[i-4]+arr[i-3]+arr[i-2]+arr[i-1]
for _ in range(int(input())):
    print(arr[int(input())])