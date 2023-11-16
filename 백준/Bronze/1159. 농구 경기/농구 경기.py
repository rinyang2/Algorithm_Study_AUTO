from collections import Counter
print((lambda x:(lambda y:''.join(sorted(y)) if len(y)!=0 else 'PREDAJA')([i for i in x if x[i]>=5]))(dict(Counter([input()[0]for _ in range(int(input()))]))))