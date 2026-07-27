#include<bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>>edges;
unordered_map<string, bool>vis;
unordered_map<string, int>colors;
bool ok = false;

bool dfs(string u) {
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
    int t, tempt;
    cin >> t;
    tempt = 1;
    while(t--) {
        set<string>horse;
        int m;
        cin >> m;
        for(int i = 0;i < m;i++) {
            string u, v;
            cin >> u >> v;
            horse.insert(u), horse.insert(v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        bool flag = true;
        for(auto u : horse) {
            if(!vis[u]) {
                colors[u] = 0;
                if(!dfs(u)) {
                    flag = false;
                    cout << "Case #" << tempt++ << ": No" << '\n';
                    break;
                }
            }
        }
        edges.clear(), vis.clear(), colors.clear();
        if(flag) cout << "Case #" << tempt++ << ": Yes" << '\n';
    }
    return 0;
}