arr=[float(input())for _ in range(int(input()))]
dp=[arr[0]]
for i in range(1,len(arr)):
    dp.append(max(dp[i-1]*arr[i], arr[i]))
print("%.3f"%max(dp))