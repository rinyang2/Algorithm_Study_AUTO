import sys

T = int(input())
arr = []
left = 3
right = 1
for i in range(101):
    temp = left
    left = (temp * 3 + right * 5)%1000
    right = (temp + right * 3)%1000
    arr.append(left)
    
for test_case in range(1, T+1):
    n = int(sys.stdin.readline())
    ans2 = '000' + str(arr[1:][(n-3)%100] *2 -1)
    print("Case #{}: {}".format(test_case,'027' if n==2 else ans2[-3:]))