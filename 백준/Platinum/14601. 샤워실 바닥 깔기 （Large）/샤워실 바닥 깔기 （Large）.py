#판의 크기를 입력받음
k = int(input())
n = 2**k
#구멍의 좌표를 입력받음
y, x = input().split()
x = int(x)
y = int(y)

#빈 판 생성
arr = [[0 for col in range(n)]for row in range(n)]

#판에 구멍 만듬
arr[n-x][y-1] = '-1'

temp = 0

#범위 내의 공간이 비어있는지 체크
def check(x, y, n):
    for i in range(x, x+n):
        for j in range(y, y+n):
            if arr[i][j]!=0:
                return False
    return True


def fill(x, y, n):
    global temp
    temp += 1
    s = int(n/2)
    if check(x,y,s):
        arr[x+s-1][y+s-1] = temp
    if check(x,y+s,s):
        arr[x+s-1][y+s] = temp
    if check(x+s,y,s):
        arr[x+s][y+s-1] = temp
    if check(x+s,y+s,s):
        arr[x+s][y+s] = temp
    if n ==2:
        return
#재귀를 이용한 분할정복
    fill(x,y,s)
    fill(x+s,y,s)
    fill(x,y+s,s)
    fill(x+s,y+s,s)
fill(0,0,n)    

#정답 출력부분
for i in arr:
    for j in i:
        print(j, end=' ')
    print()