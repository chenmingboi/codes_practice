#include<bits/stdc++.h>
using namespace std;

//这道题具有涉及顶点的性质所以最好用prime
//prime
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
vector<bool>vis;
vector<int>dis;
vector<int>weight;

int prime(int n, int s) {
    priority_queue<Node, vector<Node>, greater<Node>> q;
    q.push({s, weight[s]});
    int nodeCnt = 0, ans = 0;
    while(!q.empty()) {
        if(nodeCnt == n) break;
        int u = q.top().u, d = q.top().dis;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        ans += d;
        nodeCnt++;
        for(const auto& edge : edges[u]) {
            int v = edge.v;
            //这里改为求边权重和weight[v]的最小值，因为连接v有两种方式
            //一种是通过u->v的边权重，一种是通过添加v的顶点权重
            int w = min(edge.w, weight[v]);
            if(dis[v] > w) {
                dis[v] = w;
                q.push({v, dis[v]});
            }
        }
    }
    if(nodeCnt == n) {
        return ans;
    } else {
        return INF;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    edges.resize(n+1), weight.resize(n+1);
    for(int i = 1;i <= n;i++) {
        cin >> weight[i];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            int cost = 0;
            cin >> cost;
            edges[i].push_back({j, cost});
            edges[j].push_back({i, cost});
        }
    }
    int ans = INF;
    for(int i = 1;i <= n;i++) {
        dis.assign(n+1, INF), vis.assign(n+1, false);
        ans = min(prime(n, i), ans);
    }
    cout << ans;
    return 0;
}   