#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, curMax = 0, ans = INT_MIN;
    cin >> n;
    for(int i = 0;i < n;i++) {
        int a;
        cin >> a;
        //curMax：以当前元素结尾的最大字段和
        //ans：全局最大字段和
        //是当前元素自己单独开始一个新字段，还是延续之前的子段
        curMax = max(a, curMax + a);
        ans = max(ans, curMax);
    }
    cout << ans;
    return 0;
}