while True:
    a,b,c=input().split()
    if a+b+c == "#00":
        break
    print(a+(' Senior' if (int(b)>17 or int(c)>=80) else ' Junior'))