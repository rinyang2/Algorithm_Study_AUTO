print(list(map(int,input().split()))[1]*min((lambda x:[x[i]+x[i+1]for i in range(len(x)-1)])(list(map(int,input().split())))))