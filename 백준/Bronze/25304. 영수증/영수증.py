print('Yes' if int(input()) == sum([(lambda x:x[0]*x[1])(list(map(int, input().split())))for _ in range(int(input()))]) else 'No')