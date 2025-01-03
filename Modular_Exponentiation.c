#include<stdio.h>
typedef long long ll;

int evaluate(ll base, ll power, ll mod) {
    long long ans = 1;
    base = (base % mod + mod) % mod; // negative base handling
    while(power != 0) {
        if(power & 1) ans = (ans * base) % mod; // if current bit is on
        base = (base * base) % mod;
        power >>= 1; // to check next bit of power, divide by 2 using right shift
    }
    return ans;
}

int main() {
    ll B, N, M;
    printf("Enter base, power and mod value: ");
    scanf("%lld%lld%lld", &B, &N, &M);

    if(M <= 1 || N < 0) printf("Invalid input\n");
    else printf("Result is: %d", evaluate(B, N, M));
    return 0;
}