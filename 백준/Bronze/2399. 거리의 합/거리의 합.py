print(sum((lambda y,x: [sum([abs(x[i]-x[j]) for i in range(len(x))]) for j in range(len(x))])(int(input()),list(map(int, input().split())))))
