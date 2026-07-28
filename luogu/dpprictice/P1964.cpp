#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    unordered_map<string, int>cnt;
    set<string>name;
    vector<pair<string, int>>wupin;
    unordered_map<string, int>value;
    unordered_map<string, int>store;
    for(int i = 0;i < n;i++) {
        int a, b, c;
        string st;
        cin >> a >> b >> c >> st;
        cnt[st] += a;
        value[st] = b;
        store[st] = c;
        name.insert(st);
    }
    for(auto st : name) {
        while(cnt[st] >= store[st]) {
            wupin.push_back({st, store[st]});
            cnt[st] -= store[st];
        }
        if(cnt[st]) wupin.push_back({st, cnt[st]});
    }
    //dp[i]表示的是i格中最多能买多少钱的物品
    int left = 21-m;
    vector<int>dp(left+1, 0);
    dp[0] = 0;
    for(auto [st, num] : wupin) {
        for(int i = left;i >= 1;i--) {
            dp[i] = max(dp[i], dp[i-1] + num * value[st]);
        }
    }
    cout << dp[left];
    return 0;
}