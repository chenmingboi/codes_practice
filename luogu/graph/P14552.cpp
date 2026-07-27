#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
//colors=-1表示没有被染色
vector<int>colors;
vector<vector<int>>cnt(2);
vector<bool>vis;

void dfs(int u) {
    vis[u] = true;
    cnt[colors[u]].push_back(u);
    for(auto v : edges[u]) {
        if(colors[v] == -1) {
            colors[v] = colors[u] ^ 1;
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n;
    edges.resize(n+1), colors.resize(n+1, -1), vis.resize(n+1, false);
    for(int i = 0;i < n;i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cin >> k;
    vector<int>ans;
    //这里可能会有多个连通分量，所以可以把不同连通分量之间的结果进行相加
    //而不是只对每个连通分量进行判断
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) {
            cnt[0].clear(), cnt[1].clear();
            colors[i] = 0;
            dfs(i);
            if(cnt[0].size() > cnt[1].size()) {
                for(auto it : cnt[0]) ans.push_back(it);
            } else {
                for(auto it : cnt[1]) ans.push_back(it);
            }
        }
    }
    if(ans.size() >= k) {
        for(int i = 0;i < k;i++) cout << ans[i] << ' ';
    } else {
        cout << 0;
    }
    return 0;
}