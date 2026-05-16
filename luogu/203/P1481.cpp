#include<bits/stdc++.h>
using namespace std;

bool isPrefix(const string& a, const string& b) {
    //判断a是否是b的前缀
    if(a.size() > b.size()) return false;
    int len = a.size();
    for(int i = 0;i < len;i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans = 0;
    cin >> n;
    vector<string>words(n);
    //表示第i个单词的最长词链
    vector<int>dp(n);
    for(int i = 0;i < n;i++) {
        dp[i] = 1;
        cin >> words[i];
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < i;j++) {
            if(isPrefix(words[j], words[i])) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    for(int i = 0;i < n;i++) ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}