#include<bits/stdc++.h>
using namespace std;

//这种不确定初始节点的题型推荐用虚拟源节点

const int INF = 0x3f3f3f3f;

struct Edge{
    int v;
    int w;
};

struct Node{
    int u;
    int dis;
    bool operator>(const Node& other) const { return dis > other.dis; }
};

vector<vector<Edge>>edges;
vector<int>minCost;
vector<bool>vis;
vector<int>cost;

int prime(int s, int n) {
    priority_queue<Node, vector<Node>, greater<Node>>q;
    //虚拟源节点的花费为0
    q.push({s, 0});
    int cnt = 0, ans = 0;
    while(!q.empty()) {
        if(cnt == n) break;
        int u = q.top().u, d = q.top().dis;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        ans += d;
        cnt++;
        for(const auto& edge : edges[u]) {
            int v = edge.v;
            //选择单独打井还是连接两块田地
            int w = min(cost[v], edge.w);
            if(minCost[v] > w) {
                minCost[v] = w;
                q.push({v, w});
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    edges.resize(n+1), vis.resize(n+1, false);
    minCost.resize(n+1, INF), cost.resize(n+1);
    for(int i = 1;i <= n;i++) {
        cin >> cost[i];
        //初始话虚拟源节点到各个节点之间的cost，均为单独打井的花费
        edges[0].push_back({i, cost[i]});
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            int p;
            cin >> p;
            //p == 0代表没有边相连
            if(p != 0) {
                edges[i].push_back({j, p});
            }
        }
    }
    //加上虚拟源节点一共n+1个节点
    cout << prime(0, n+1);
    return 0;
}
//下面的写法仅在给出的邻接矩阵对应的图是连通的情况下适用
//因为，如果初始给出的图不连通，且prim算法是通过遍历节点的边来添加节点
//就会导致有的节点不会被遍历到，就不会被添加到最小生成树中
// //这道题具有涉及顶点的性质所以最好用prim
// //prime
// const int INF = 0x3f3f3f3f;
// struct Edge{
//     int v;
//     int w;
// };

// struct Node{
//     int u;
//     int dis;
//     bool operator>(const Node& other) const { return dis > other.dis; }
// };

// vector<vector<Edge>>edges;
// vector<bool>vis;
// vector<int>dis;
// vector<int>weight;

// int prime(int n, int s) {
//     priority_queue<Node, vector<Node>, greater<Node>> q;
//     q.push({s, weight[s]});
//     int nodeCnt = 0, ans = 0;
//     while(!q.empty()) {
//         if(nodeCnt == n) break;
//         int u = q.top().u, d = q.top().dis;
//         q.pop();
//         if(vis[u]) continue;
//         vis[u] = true;
//         ans += d;
//         nodeCnt++;
//         for(const auto& edge : edges[u]) {
//             int v = edge.v;
//             //这里改为求边权重和weight[v]的最小值，因为连接v有两种方式
//             //一种是通过u->v的边权重，一种是通过添加v的顶点权重
//             int w = min(edge.w, weight[v]);
//             if(dis[v] > w) {
//                 dis[v] = w;
//                 q.push({v, dis[v]});
//             }
//         }
//     }
//     if(nodeCnt == n) {
//         return ans;
//     } else {
//         return INF;
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     cin >> n;
//     edges.resize(n+1), weight.resize(n+1);
//     for(int i = 1;i <= n;i++) {
//         cin >> weight[i];
//     }
//     for(int i = 1;i <= n;i++) {
//         for(int j = 1;j <= n;j++) {
//             int cost = 0;
//             cin >> cost;
//             edges[i].push_back({j, cost});
//             edges[j].push_back({i, cost});
//         }
//     }
//     int ans = INF;
//     for(int i = 1;i <= n;i++) {
//         dis.assign(n+1, INF), vis.assign(n+1, false);
//         ans = min(prime(n, i), ans);
//     }
//     cout << ans;
//     return 0;
// }   