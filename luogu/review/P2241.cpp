#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    long long ans1 = 0, ans2 = 0;
    for(int i = 0;i <= min(n-1, m-1);i++) {
        ans1 += 1LL * (n-i) * (m-i);
    }
    for(int i = 0;i <= n-1;i++) {
        for(int j = 0;j <= m-1;j++) {
            if(j != i) {
                ans2 += 1LL * (n-i) * (m-j);
            }
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}