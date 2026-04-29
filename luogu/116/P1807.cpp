#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>>edges(n+1);
    vector<int>dp(n+1, INT_MIN);
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }
    bool flag = false;
    queue<int>q;
    q.push(1);
    dp[1] = 0;
    while(!q.empty()) {
        int u = q.front();
        if(u == n) flag = true;
        for(auto edge : edges[u]) {
            int v = edge.first, w = edge.second;
            int newDp = dp[u] + w;
            //只有大于的时候才push进去，防止重复无效的遍历
            //dp先赋值为INT_MIN，因为w可能小于0, 使得有些节点本该push进来
            //但是由于dp初始值的限制却没有push进来
            if(newDp > dp[v]) {
                dp[v] = newDp;
                q.push(v);
            } 
        }
        q.pop();
    }
    if(flag) {
        cout << dp[n];
    } else {
        cout << -1;
    }
    return 0;
}