#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    long long ans1 = 0LL, ans2 = 0LL;
    int sm = min(n, m);
    for(int i = 1;i <= sm;i++) {
        ans1 += 1LL * (n+1-i) * (m+1-i);
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(i == j) continue;
            ans2 += 1LL * (n+1-i) * (m+1-j);
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}