#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n; 
    vector<int>num(n+1);
    vector<vector<int>>pre(n+1);
    vector<int>dp(n+1);
    vector<vector<int>>path(n+1);
    for(int i = 1;i <= n;i++) cin >> num[i];
    for(int i = 1;i <= n-1;i++) {
        for(int j = i+1;j <= n;j++) {
            int judge;
            cin >> judge;
            if(judge) pre[j].push_back(i);
        }
    }
    //dp[i]表示终点为i时的所有路径中能挖到的最多地雷数
    dp[0] = 0;
    for(int i = 1;i <= n;i++) {
        if(pre[i].size() == 0) {
            dp[i] = num[i];
            path[i].push_back(i);
        } else {
            int maxNum = 0;
            int lastNode = 0;
            for(auto u : pre[i]) {
                if(dp[u] > maxNum) {
                    maxNum = dp[u];
                    lastNode = u;
                }
            }
            if(maxNum + num[i] > dp[i]) {
                dp[i] = maxNum + num[i];
                for(auto node : path[lastNode]) {
                    path[i].push_back(node);
                }
                path[i].push_back(i);
            }
        }
    }
    int ans = 0;
    int node = 0;
    for(int i = 1;i <= n;i++) {
        if(dp[i] > ans) {
            ans = dp[i];
            node = i;
        }
    }
    for(auto it : path[node]) {
        cout << it << ' ';
    }
    cout << endl;
    cout << ans;
    return 0;
}