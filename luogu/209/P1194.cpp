#include<bits/stdc++.h>
using namespace std;

//这道题明显具有点的性质，感觉prime算法更适合
const int INF = 0x3f3f3f3f;

struct Edge{
    int v;
    int w;
};

struct Node{
    int u;
    //dis表示的是u的前一个节点到该节点的花费
    int dis;
    bool operator>(const Node& other) const {
        return dis > other.dis;
    }
};

vector<vector<Edge>>edges;
vector<bool>vis;
vector<int>minCost;
vector<int>cost;

int prime(int s, int n) {
    priority_queue<Node, vector<Node>, greater<Node>> q;
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
            //这里错误，因为kij可能为0，此时i和j之间就不会添加edge
            //从而不保证给出的优惠图是一个连通图，所以有些节点可能会遍历不到
            //这里推荐用虚拟源节点来处理，通过添加虚拟源节点0,再添加源节点到每个节点
            //之间的边，边的权重为cost[i]，从而求添加过源节点之后的最小生成树即可
            //edge.w表示通过优惠购买，cost[v]表示通过原价购买
            int w = min(edge.w, cost[v]);
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
    int a, b;
    cin >> a >> b;
    edges.resize(b+1), cost.resize(b+1, a);
    for(int i = 1;i <= b;i++) {
        //添加源节点到每个节点之间的边
        edges[0].push_back({i, a});
    }
    for(int i = 1;i <= b;i++) {
        for(int j = 1;j <= b;j++) {
            int k;
            cin >> k;
            //不等于0表示两个节点之间存在边
            if(k != 0) {
                //这里是虽然是双向边，但是是邻接矩阵，之后自会添加j->i的边
                edges[i].push_back({j, k});
            }
        }
    }
    // int ans = INF;
    // for(int i = 1;i <= b;i++) {
    //     vis.assign(b+1, false), minCost.assign(b+1, INF);
    //     ans = min(ans, prime(i, b));
    // }
    //这里就不需要循环遍历每个节点了
    vis.resize(b+1, false), minCost.resize(b+1, INF);
    cout << prime(0, b+1);
    return 0;
}