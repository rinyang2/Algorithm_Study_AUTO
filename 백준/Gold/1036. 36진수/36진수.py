import sys

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
dic = {}
dic_reversed = {}
count = []
for i in range(10):
    count.append([str(i),0])
    dic[str(i)] = i
for i in range(26):
    count.append([alphabet[i],0])
    dic[alphabet[i]] = i+10
    dic_reversed[i+10] = alphabet[i]
#function to translate 36 to int
def to_int_36(s):
    ans = 0
    s = s[::-1]
    temp = 1
    for c in range(len(s)):
        try:
            ans += int(s[c])*temp
        except:
            ans += dic[s[c]]*temp
        temp *=36
    return ans

def to_36_int(n):
    if n == 0:
        return '0'
    result = ''
    while n:
        n, mod = divmod(n, 36)
        if mod<10:
            result += str(mod)
        else:
            result += dic_reversed[mod]
    return result [::-1]

N = int(sys.stdin.readline())

arr = []
for i in range(N):
    arr.append(sys.stdin.readline().rstrip())
K = int(sys.stdin.readline())

for num in arr:
    temp = 1
    for c in num[::-1]:
        count[dic[c]][1] += temp
        temp *= 36
count.sort(key = lambda x: x[1] * (35-dic[x[0]]), reverse = True)
for i in range(K):
    count[i][0] = 'Z'
ans = 0

for i in count:
    ans += dic[i[0]] * i[1]
print(to_36_int(ans))