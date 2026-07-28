#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int levels, levelt, m, n, limit;
    cin >> levels >> levelt >> m >> n;
    vector<int>time(n);
    vector<pair<int, int>>value(m+1);
    for(int i = 0;i < n;i++) {
        int t;
        cin >> t;
        time[i] = t * (levelt/levels);
    }
    for(int i = 0;i < m;i++) {
        int p, q;
        cin >> p >> q;
        value[i] = {p-1, q};
    }
    cin >> limit;
    //这道题不是分组背包，分组背包是每一组中只能选择一个
    //这道题就是普通的0/1背包，只不过索引稍微复杂一点
    vector<int>dp(limit+1, 0);
    for(int i = 0;i < m;i++) {
        for(int j = limit;j >= time[value[i].first];j--) {
            dp[j] = max(dp[j], dp[j-time[value[i].first]] + value[i].second);
        }
    }
    // for(int i = 0;i < n;i++) {
    //     for(int j = time[i];j <= limit;j++) {
    //         //这里同一组中可以选择多个，如果使用j倒序遍历则表达的意思是从改知识点的题目中只挑选一道max来更新dp[j]
    //         //和前面题不同的这是逐个遍历题目所以要使用正序，选择一道题之后同样还可以再次选择该知识点中的题
    //         //前面题目中最里面的循环是选择几个，同一组的元素中是一样的，所以要倒序遍历因为选择几个已经是列举选择的情况了
    //         //选过一个之后不能影响后面选择两个的判断
    //         for(auto v : value[i]) {
    //             dp[j] = max(dp[j], dp[j-time[i]] + v);
    //         }
    //     }
    // }
    cout << dp[limit];
    return 0;
}