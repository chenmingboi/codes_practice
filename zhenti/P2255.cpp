#include<bits/stdc++.h>
using namespace std;

const int MOD = 10007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int b, g, k;
    cin >> b >> g >> k;
    int block = b / k;
    int res = b % k;
    int ans = 1;
    if(res == 0) {
        g -= (block-1);
        while(g) {
            ans *= (b+block);
            ans %= MOD;
            g--;
        }
    } else {
        g -= block;
        while(g) {
            ans *= (b+block+1);
            ans %= MOD;
            g--;
        }
        ans += block;
        ans %= MOD;
        ans += block;
        ans %= MOD;
    }
    cout << ans;
    return 0;
}