#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>m(n);
    for(int i = 0;i < n;i++) cin >> m[i];
    sort(m.begin(), m.end());
    long long ans = 1LL;
    bool flag = true;
    for(int i = 0;i < n;i++) {
        if(m[i] - 1 < i) {
            flag = false;
            break;
        }
        ans *= (m[i]-i);
        ans %= (long long)(1e9+7);
    }
    if(flag) {
        cout << ans;
    } else {
        cout << 0;
    }
    return 0;
}