#include<bits/stdc++.h>
using namespace std;

/*
边双连通分量模板(Edge-Biconnected Component, e-BCC)模板
使用vector存图+tarjan存桥+DFS收集分量
先使用tarjan算法找出所有桥
删掉桥之后剩下的连通块就是边双连通分量
*/

int n, m;//点数，边数
int ans;//边双连通分量的个数
vector<vector<pair<int, int>>>edges; //edge[u]保存{邻居v, 边编号eid};
vector<char> is_bridge;
vector<int>dfn, low, vis_bcc;//dfn记录时间戳，low记录不经过父边能到达的最早到达边的记号
//vis_bcc表示点所属的边双连通分量编号（0表示未访问）
int tot = 0;//全局时间计时器
vector<vector<int>>bcc;//存储每个边双连通分量包含的点

//u为当前节点，in_edge进入当前点的边编号（用于避免立刻走回头边）
void tarjan(int u, int in_edge) {
    //inedge-> u -eid->v
    dfn[u] = low[u] = ++tot;
    for(auto [v, eid] : edges[u]) {
        if(!dfn[v]) {
            tarjan(v, eid);
            low[u] = min(low[u], low[v]);
            //判断是否为桥
            //如果u的子节点v为根节点所属的连通分量除了 eid 这条边之外
            //没有其他边能够到达u或者u的祖先，则eid这条边就是一个桥
            if(dfn[u] < low[v]) {
                //2^1 = 3, 3 ^ 1 = 2
                is_bridge[eid] = true; //标记正向边为桥
                is_bridge[eid^1] = true; //同时标记反向边为桥
            }
        } else if(eid != (in_edge ^ 1)) {
            //如果已经访问过了，且不是到达u的那条边，说明找到了回边
            //这个判断条件判断的是 eid不是in_edge的反向边 fa -inedge->u    fa<-eid-u
            low[u] = min(low[u], dfn[v]);
        }
    }
}

/*
深度优先所搜收集同一个边双连通分量的点
只走非桥边
u表示当前点，id表示当前边双连通分量的编号
*/
void dfs(int u, int id) {
    vis_bcc[u] = id;//标记该店属于第id个连通分量 (从1开始)
    bcc[id-1].push_back(u);//把点加入对应的连通分量（bcc下标是从0开始的）
    for(auto [v, eid] : edges[u]) {
        if(vis_bcc[v] || is_bridge[eid]) continue;
        dfs(v, id);//继续在同一个分量内搜索
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    edges.resize(n+1), dfn.resize(n+1), low.resize(n+1), vis_bcc.resize(n+1);
    is_bridge.resize(2*m + 1, 0);
    int edge_cnt = 0;
    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        if(u == v) continue;//自环对边双连通分量无影响，直接跳过
        //无向边拆成两条有向边，编号连续（0， 1， 2， 3...
        //这样可以利用eid^1快速找到反边
        edges[u].emplace_back(v, edge_cnt);
        edges[v].emplace_back(u, edge_cnt+1);
        edge_cnt += 2;
    }
    //找出所有的桥
    for(int i = 1;i <= n;i++) {
        if(!dfn[i]) {
            tarjan(i, -1); //起点没有入边，传入-1
        }
    }
    for(int i = 1;i <= n;i++) {
        if(!vis_bcc[i]) { //还没有被分到任何连通分量
            bcc.emplace_back();//新建一个空分量
            dfs(i, ++ans);//ans从1开始编号
        }
    }
    cout << ans << '\n';
    for(int i = 0;i < ans;i++) {
        cout << bcc[i].size();
        for(int x : bcc[i]) cout << ' ' << x;
        cout << '\n';
    }
    return 0;
}