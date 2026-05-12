#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p;
    cin >> n >> p;
    vector<int>a(n+1, 0), d(n+2, 0);
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        d[i] = a[i]-a[i-1];
    }
    for(int i = 0;i < p;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        //这样计算[x,y]中的a[i]的时候会叠加d[x]所加的z，然后超出y之后又会取消所加的z
        d[x] += z;
        d[y+1] -= z;
    }
    int ans = INT_MAX;
    for(int i = 1;i <= n;i++) {
        a[i] = a[i-1] + d[i];
        ans = min(ans, a[i]);
    }
    cout << ans;
    return 0;
}