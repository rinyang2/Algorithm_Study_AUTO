N,M = map(int, input().split())
MOD = 1000000007
def pow_modulo(a, b, c):
    if b == 0:
        return 1
    temp = pow_modulo(a, b//2, c) % c
    temp = (temp * temp) % c
    if b % 2 == 1:
        temp = (temp * a) % c
    return temp

print(pow_modulo(2,N,MOD)-1 if M==1 else ((pow_modulo(2,N+1,MOD)+MOD-2)*M+MOD-1)%MOD)