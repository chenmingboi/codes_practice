#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    //数组s记录前缀和
    vector<int>a(n+1, 0), s(n+1, 0);
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    cin >> m;
    for(int i = 0;i < m;i++) {
        int l, r;
        cin >> l >> r;
        //[l, r]区间和为s[r] - s[l-1]
        cout << s[r] - s[l-1] << endl;
    }
    return 0;
}