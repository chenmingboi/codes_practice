#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>>edges;
vector<int>dfn, low, belong_scc;
vector<char>is_bridge;
vector<vector<int>>scc;
vector<int>scc_weight;
vector<int>a;
int tot = 0, scc_cnt = 0;

void tarjan(int u, int in_edgeid) {
    dfn[u] = low[u] = ++tot;
    for(auto [v, eid] : edges[u]) {
        if(!dfn[v]) {
            tarjan(v, eid);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]) {
                is_bridge[eid] = is_bridge[eid^1] = true;
            }
        } else if(eid != (in_edgeid ^ 1)) {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void dfs(int u, int scc_id) {
    belong_scc[u] = scc_id;
    scc[scc_id].emplace_back(u);
    scc_weight[scc_id] += a[u];
    for(auto [v, eid] : edges[u]) {
        if(belong_scc[v] || is_bridge[eid]) continue;
        dfs(v, scc_id);
    }
}

//使用LCA优化和树上差分
vector<vector<int>>dag, fa;
vector<int>dep;
vector<int>diff;

void dfs_tree(int u, int f) {
    fa[u][0] = f;
    dep[u] = dep[f]+1;
    for(int i = 1;i < 20;i++) {
        fa[u][i] = fa[fa[u][i-1]][i-1];
    }
    for(auto v : dag[u]) {
        if(v != f) dfs_tree(v, u);
    }
}

int lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    //先把u跳到和v相同的高度
    for(int i = 19;i >= 0;i--) {
        if(dep[fa[u][i]] >= dep[v]) {
            u = fa[u][i];
        }
    }
    if(u == v) return u;
    for(int i = 19;i >= 0;i--) {
        if(fa[u][i] != fa[v][i]) {
            u = fa[u][i], v = fa[v][i];
        }
    }
    //最后u和v调到了同一fa下面
    return fa[u][0];
}

void add_path(int u, int v) {
    int p = lca(u, v);
    diff[u]++;
    diff[v]++;
    diff[p]--;
    //在lca处得到加1, 然后应该是不要继续往上传
    //所以要对lca的fa进行减一
    if(fa[p][0]) diff[fa[p][0]]--;
}

//下推差分
void push_diff(int u, int f) {
    for(int v : dag[u]) {
        if(v == f) continue;
        push_diff(v, u);
        diff[u] += diff[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    edges.resize(n+1), dfn.resize(n+1), low.resize(n+1);
    belong_scc.resize(n+1), is_bridge.resize(2*m+1, 0);
    a.resize(n+1), scc.emplace_back(), scc_weight.resize(n+1);
    int edge_cnt = 0;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        edges[u].emplace_back(v, edge_cnt);
        edges[v].emplace_back(u, edge_cnt+1);
        edge_cnt += 2;
    }
    for(int i = 1;i <= n;i++) {
        if(!dfn[i]) tarjan(i, -1);
    }
    for(int i = 1;i <= n;i++) {
        if(!belong_scc[i]) {
            scc.emplace_back();
            scc_cnt += 1;
            dfs(i, scc_cnt);
        }
    }
    dag.resize(scc_cnt+1);
    long long ans = 0;
    for(int u = 1;u <= n;u++) {
        for(auto [v, eid] : edges[u]) {
            int a = belong_scc[u], b = belong_scc[v];
            if(a < b) { 
                //用小于号替代!=既可以满足不等于的要求,又可以避免添加重复边
                dag[a].push_back(b);
                dag[b].push_back(a);
            }
        }
    }
    //预处理lca
    dep.resize(scc_cnt+1);
    fa.resize(scc_cnt+1, vector<int>(20));
    diff.assign(scc_cnt+1, 0);
    dfs_tree(1, 0);
    int q;
    cin >> q;
    for(int i = 0;i < q;i++) {
        int x, y;
        cin >> x >> y;
        add_path(belong_scc[x], belong_scc[y]);
    }
    push_diff(1, 0);
    for(int i = 1;i <= scc_cnt;i++) {
        if(diff[i]) ans += scc_weight[i];
    }
    cout << ans;
    return 0;
}