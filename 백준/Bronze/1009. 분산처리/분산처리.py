print(*[(lambda x:(lambda y:y if y>0 else 10)((x[0]**(x[1]%4 if x[1]%4 else 4))%10))(list(map(int,input().split())))for _ in range(int(input()))],sep='\n')