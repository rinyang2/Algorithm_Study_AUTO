import sys
T=int(sys.stdin.readline())
dp=[[0,0,1],[1,0,0],[0,1,0],[1,1,1]]
for i in range(4,100001):
    dp.append([(dp[i-1][1]+dp[i-1][2])%1000000009,(dp[i-2][0]+dp[i-2][2])%1000000009,(dp[i-3][0]+dp[i-3][1])%1000000009])
for _ in range(T):
    print(sum(dp[int(sys.stdin.readline())])%1000000009)