#include<bits/stdc++.h>
using namespace std;

//本道题其实是斐波那契数列f(n) = f(n-1) + f(n-2);
//上到当前这一台阶只有两种走法，一种是由上一个台阶上一阶，一种是由上两个台阶上二阶

vector<int> add_str(const vector<int>& a, const vector<int>& b) {
    int len1 = a.size(), len2 = b.size();
    int len = max(len1, len2);
    vector<int>result(len+1, 0);
    for(int i = 0;i < len;i++) {
        if(i < len1 && i < len2) {
            //注意这里是+=，要处理上一位来的进位
            result[i] += a[i] + b[i];
        } else if(i < len2) {
            result[i] += b[i];
        } else if(i < len1) {
            result[i] += a[i];
        }
        result[i+1] += result[i] / 10;
        result[i] %= 10;
    }
    while(result.back() == 0 && result.size() > 1) result.pop_back();
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>init(1, 1);
    vector<vector<int>>dp(5002);
    dp[0] = init;
    dp[1] = init;
    for(int i = 2;i <= n;i++) {
        dp[i] = add_str(dp[i-1], dp[i-2]);
    }
    reverse(dp[n].begin(), dp[n].end());
    for(auto it : dp[n]) {
        cout << it;
    }
    return 0;
}