#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    //dp[i][j]表示的是[i,j]区域内获得的最大分数总和也就是删除a[i]到a[j]所能获得的最大分数
    //正向删除时每次删一个元素得分时当前左右邻居之和，反过来想，最后删除的元素是哪个？
    //当某个元素a[k]是区间[i, j]内最后一个被删除的元素的时候，删除它时[i-1][j+1]这两个元素依然存在（或者是边界）
    //所以它的得分就是a[i-1]+a[j+1]（如果超出边界相应取值为0）
    //这样问题可以分解成两个独立的子问题
    //1. 删除[i, k-1]内的元素，其有边界为k
    //2. 删除[k+1, j]内的元素，其左边界为k
    vector<vector<ll>>dp(n, vector<ll>(n, 0));
    for(int len = 1;len <= n;len++) {
        for(int i = 0;i+len-1 < n;i++) {
            int j = i+len-1;
            //枚举最后删除的元素k
            for(int k = i;k <= j;k++) {
                ll left = (k-1 >= i) ? dp[i][k-1] : 0;
                ll right = (k+1 <= j) ? dp[k+1][j] : 0;
                ll value = ((i-1 >= 0) ? a[i-1] : 0) + ((j+1 < n) ? a[j+1] : 0);
                dp[i][j] = max(dp[i][j], left + right + value);
            }
        }
    }
    cout << dp[0][n-1];
    return 0;
}