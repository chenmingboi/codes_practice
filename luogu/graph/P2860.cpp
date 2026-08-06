#include<bits/stdc++.h>
using namespace std;

int f, r;
vector<vector<pair<int, int>>>edges;
vector<int>dfn, low, belong_bcc;
vector<char>is_bridge;
vector<vector<int>>bcc;
int tot = 0;
int bcc_cnt = 0;
//找出所有的桥边
void tarjan(int u, int in_edgeid) {
    dfn[u] = low[u] = ++tot;
    for(auto [v, eid] : edges[u]) {
        if(!dfn[v]) {
            tarjan(v, eid);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]) {
                is_bridge[eid] = is_bridge[eid^1] = true;
            }
        } else if(eid != (in_edgeid^1)) {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

//标记出所有连通分量
void dfs(int u, int cnt) {
    belong_bcc[u] = cnt;
    bcc[cnt-1].emplace_back(u);
    for(auto [v, eid] : edges[u]) {
        if(belong_bcc[v] || is_bridge[eid]) continue;
        dfs(v, cnt);
    }
}


// void treedfs(int u, int fa) {
//     vis[u] = true;
//     for(auto v : dag[u]) {
//         if(!vis[v] && v != fa) {
//             leafcnt++;
//             treedfs(v, u);
//         } 
//     }
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //进行求边双连通图分量的个数，把每个边双连通图进行缩点看所一个点
    //然后进行构建一个树，求树中子节点的数量num，结果等于(num+1)/2
    cin >> f >> r;
    edges.resize(f+1), dfn.resize(f+1), low.resize(f+1), belong_bcc.resize(f+1);
    is_bridge.resize(2*r+1, 0);
    int edge_cnt = 0;
    for(int i = 0;i < r;i++) {
        int u, v;
        cin >> u >> v;
        if(u == v) continue;
        edges[u].emplace_back(v, edge_cnt);
        edges[v].emplace_back(u, edge_cnt+1);
        edge_cnt += 2;
    }
    for(int i = 1;i <= f;i++) {
        if(!dfn[i]) tarjan(i, -1);
    }
    for(int i = 1;i <= f;i++) {
        if(!belong_bcc[i]) {
            bcc.emplace_back();
            bcc_cnt += 1;
            dfs(i ,bcc_cnt);
        }
    }
    //构建新图
    vector<int>du;
    int leafcnt = 0;
    du.resize(bcc_cnt+1, 0);
    //在这里每条无向边被统计了两次
    for(int i = 1;i <= f;i++) {
        for(auto[v, eid] : edges[i]) {
            if(belong_bcc[i] != belong_bcc[v]) {
                du[belong_bcc[i]]++;
                du[belong_bcc[v]]++;
            }
        }
    }
    for(int i = 1;i <= bcc_cnt;i++) {
        if(du[i] == 2) leafcnt++;
    }
    // treedfs(0, -1);
    cout << (leafcnt+1)/ 2;
    return 0;
}