print(*(lambda x:max(x)[::-1])([[sum(list(map(int,input().split()))),i]for i in range(1,6)]))