#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    //这个方案勉强过了，这里用的是unordered_set而不是set
    //因为set做插入的时候复杂度是O(logn)而unordered_set的复杂度是O(1)
    //且后面只用到了size方法
    unordered_set<int>sum_r, sum_c;
    for(int i = 0;i < k;i++) {
        int r, c;
        cin >> r >> c;
        sum_r.insert(r), sum_c.insert(c);
    }
    long long ans = 0;
    ans += n * (sum_r.size() + sum_c.size());
    ans -= sum_c.size() * sum_r.size();
    cout << ans;
    return 0;
}