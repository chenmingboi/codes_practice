#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>g;
vector<int>cur, parent, depth;
int maxWidth = 0;
void dfs(int u, int d) {
    depth[u] = d;
    for(int v : g[u]) {
        dfs(v, d+1);
    }
    return;
}

int dist(int x, int y) {
    //求出x ,y的最近公共祖先，在这个过程中求出距离
    int dist1 = 0, dist2 = 0;
    while(depth[x] > depth[y]) {
        x = parent[x];
        dist1++;
    }
    while(depth[y] > depth[x]){
        y = parent[y];
        dist2++;
    } 
    while(x != y) {
        x = parent[x];
        y = parent[y];
        dist1++, dist2++;
    }
    return 2 * dist1 + dist2;
}
int getDepth(int node) {
    if (g[node].empty()) return 1;

    int mx = 0;
    for (int v : g[node]) {
        mx = max(mx, getDepth(v));
    }
    return mx + 1;
}

void getWidth(int node, int k) {
    //k表示当前节点深度
    cur[k]++;
    maxWidth = max(maxWidth, cur[k]);
    for(int v : g[node]) {
        getWidth(v, k+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    g.resize(n+1), cur.resize(n+1), parent.resize(n+1);
    depth.resize(n+1);
    for(int i = 0;i < n-1;i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        parent[v] = u; //记录v的父节点
    }
    dfs(1, 1);
    int x, y;
    cin >> x >> y;
    cout << getDepth(1) << endl;
    getWidth(1, 1);
    cout << maxWidth << endl;
    cout << dist(x, y);
    return 0;
}