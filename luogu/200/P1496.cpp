#include<bits/stdc++.h>
using namespace std;

int getIndex(int x, const vector<int>&vals) {
    //lower_bound返回的是迭代器
    return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans = 0;
    cin >> n;
    vector<int>vals;
    vector<int>d;
    vector<int>l(n), r(n);
    for(int i = 0;i < n;i++) {
        int a, b;
        cin >> a >> b;
        l[i] = a, r[i] = b;
        vals.push_back(a), vals.push_back(b);
    }
    sort(vals.begin(), vals.end());
    //去除重复元素
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int len = vals.size() + 2;
    d.resize(len, 0);
    for(int i = 0;i < n;i++) {
        d[getIndex(l[i], vals)+1] += 1;
        d[getIndex(r[i], vals)+1] -= 1;
    }
    int cur = 0;
    for(int i = 1;i < len;i++) {
        cur += d[i]; //cur 表示的是当前vals[i]-vals[i-1]被多少区间覆盖
        if(cur) ans += vals[i] - vals[i-1];
    }
    cout << ans;
    return 0;
}