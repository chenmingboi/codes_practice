#include<bits/stdc++.h>
using namespace std;

struct haiba{
    int index;
    int h;
};

vector<vector<int>>edges;
vector<int>height;

bool comp(const haiba& a, const haiba& b) {
    return a.h > b.h;
}

void dfs(int u, vector<bool>& vis) {
    if(vis[u]) return;
    vis[u] = true;
    for(auto v : edges[u]) {
        if(!vis[v] && height[v] < height[u]) {
            dfs(v, vis);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, maxh = 0, source;
    cin >> n >> m;
    height.resize(n+1);
    for(int i = 1;i <= n;i++) {
        cin >> height[i];
        if(height[i] > maxh) {
            maxh = height[i];
            source = i;
        }
    }
    edges.resize(n+1);
    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    bool flag = true;
    vector<bool>vis(n+1, false);
    dfs(source, vis);
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) {
            flag = false;
            break;
        }
    }
    if(!flag) {
        cout << "Non";
    } else {
        cout << "Oui, j'ai trouve la solution." << endl;
        cout << source;
    }
    return 0;
}