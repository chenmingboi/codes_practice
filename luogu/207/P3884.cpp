#include<bits/stdc++.h>
using namespace std;

const int LOG = 20;
vector<vector<int>>edges;
vector<vector<int>>fa;
vector<int>depth;

int d = INT_MIN, w = INT_MIN, dis;

void dfs(int u, int father) {
    depth[u] = depth[father] + 1;
    d = max(d, depth[u]);
    fa[u][0] = father;
    for(int i = 1;i <= LOG;i++) {
        fa[u][i] = fa[fa[u][i-1]][i-1];
    }
    for(auto v : edges[u]) {
        dfs(v, u);
    }
}

void bfs(int u) {
    queue<int>q;
    q.push(u);
    while(!q.empty()) {
        int sz = q.size();
        w = max(w, sz);
        //遍历一整层
        for(int i = 0;i < sz;i++) {
            int front = q.front();
            q.pop();
            for(auto v : edges[front]) {
                q.push(v);
            }
        }
    }
}

int lca(int u, int v) {
    if(u == v) return u;
    if(depth[u] < depth[v]) swap(u, v);
    //注意这里是到0
    for(int i = LOG;i >= 0;i--) {
        if(depth[fa[u][i]] >= depth[v]) {
            u = fa[u][i];
        }
    }
    if(u == v) return u;
    for(int j = LOG;j >= 0;j--) {
        if(fa[u][j] != fa[v][j]) {
            u = fa[u][j];
            v = fa[v][j];
        }
    }
    return fa[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    cin >> n;
    edges.resize(n+1), fa.resize(n+1, vector<int>(LOG+1, 0));
    depth.resize(n+1);
    for(int i = 0;i < n-1;i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }
    cin >> x >> y;
    dfs(1, 0);
    bfs(1);
    int father = lca(x, y);
    //x 到 y 的距离，注意是有向的
    dis = 2 * (depth[x] - depth[father]) + depth[y] - depth[father];
    cout << d << endl << w << endl << dis;
    return 0;
}