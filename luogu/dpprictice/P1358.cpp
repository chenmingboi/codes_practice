#include<bits/stdc++.h>
using namespace std;

const int MOD = 10007;
vector<int>frac, invfrac;

long long modpow(long long a, long long e) {
    //求逆元a^e mod MOD
    long long res = 1;
    while(e) {
        if(e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

int cab(int a, int b) {
    return frac[a] * invfrac[b] % MOD * invfrac[a-b] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>a(m);
    for(int i = 0;i < m;i++) cin >> a[i];
    frac.resize(n+1), invfrac.resize(n+1);
    frac[0] = 1;
    for(int i = 1;i <= n;i++) frac[i] = frac[i-1] * i % MOD;
    //费马小定理求逆元 a * a^(p-2) = 1 (% MOD)
    invfrac[n] = modpow(frac[n], MOD-2);
    for(int i = n;i >= 1;i--) invfrac[i-1] = invfrac[i] * i % MOD;
    int ans = 1;
    for(int i = 0;i < m;i++) {
        ans *= cab(n, a[i]);
        ans %= MOD;
        n -= a[i];
    }
    cout << ans;
    return 0;
}