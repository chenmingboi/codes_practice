#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
vector<bool>vis;
vector<int>colors;

bool dfs(int u) {
    vis[u] = true;
    for(auto v : edges[u]) {
        if(!vis[v]) {
            colors[v] = colors[u] ^ 1;
            if(!dfs(v)) return false;
        } else {
            if(colors[u] == colors[v]) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        edges.resize(n+1), vis.resize(n+1, false), colors.resize(n+1);
        for(int i = 0;i < n;i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        bool flag = true;
        for(int i = 1;i <= n;i++) {
            if(!vis[i]) {
                colors[i] = 0;
                if(!dfs(i)) {
                    cout << 3 << '\n';
                    flag = false;
                    break;
                }
            }
        }
        if(flag) cout << 2 << '\n';
        edges.clear(), vis.clear(), colors.clear();
    }
    return 0;
}