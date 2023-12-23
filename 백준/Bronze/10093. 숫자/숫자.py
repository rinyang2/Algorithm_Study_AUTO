a=(lambda x:[i for i in range(x[0]+1,x[1])])(sorted(list(map(int,input().split()))))
print(len(a))
if len(a)>0:
    print(*a)