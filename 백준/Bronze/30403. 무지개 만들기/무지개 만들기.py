n = int(input())
q = input()
dic = {}
for a in "abcdefghijklmnopqrstuvwxyzQWERTYUIOPASDFGHJKLZXCVBNM":
    dic[a] = 0
for a in q:
    dic[a] = 1
asd = 1
sdf = 1
for a in "ROYGBIV":
    asd *= dic[a]
for a in "roygbiv":
    sdf *= dic[a]
if asd==1:
    if sdf == 1:
        print("YeS")
    else:
        print("YES")
elif sdf ==1:
    print("yes")
else:
    print("NO!")