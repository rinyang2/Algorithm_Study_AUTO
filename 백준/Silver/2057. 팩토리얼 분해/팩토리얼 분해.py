from itertools import combinations
arr = []
for i in range(999):
    x = 1
    for j in range(1,i+1):
        x*=j
    if x>1000000000000000000:
        break
    arr.append(x)
ans = []
for i in range(1,len(arr)+1):
    for x in list(combinations(arr,i)):
        temp = sum(x)
        if temp<=1000000000000000000:
            ans.append(temp)
print("YES"if int(input())in ans else"NO")