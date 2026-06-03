#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
struct Edge {
    int v;
    int w;
};

struct Node{
    int u;
    int cost;
    bool operator>(const Node&other) const {
        return cost > other.cost;
    }
};

vector<vector<Edge>>edges;
vector<int>minCost;
vector<bool>inTree;

int prim(int n, int a) {
    int result = 0;
    int nodeCnt = 0;
    priority_queue<Node, vector<Node>, greater<Node>>q;
    //这里引入虚拟源节点
    q.push({0, 0});
    while(!q.empty()) {
        int u = q.top().u, cost = q.top().cost;
        q.pop();
        if(inTree[u]) continue;
        inTree[u] = true;
        result += cost;
        nodeCnt++;
        for(auto edge : edges[u]) {
            int v = edge.v, w = edge.w;
            if(w == 0) {
                w = a;
            }
            if(minCost[v] > w) {
                minCost[v] = w;
                q.push({v, w});
            }
        }
        if(nodeCnt == n+1) break;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    edges.resize(b+1);
    inTree.resize(b+1, false);
    minCost.resize(b+1, INF);
    for(int i = 1;i <= b;i++) {
        edges[0].push_back({i, 0});
    }
    for(int i = 1;i <= b;i++) {
        for(int j = 1;j <= b;j++) {
            int k;
            cin >> k;
            k = min(k, a);
            edges[i].push_back({j, k});
        }
    }
    int ans = prim(b, a);
    cout << ans;
    return 0;
}
// //没想到这一版竟然写对了，但是还是推荐使用虚拟源节点
// //这样就不用在main中循环遍历使用节点来确定最终正确结果
// const int INF = 0x3f3f3f3f;

// struct Edge {
//     int v;
//     int w;
// };

// struct Node {
//     int u;
//     int cost;
//     bool operator>(const Node& other) const {
//         return cost > other.cost;
//     }
// };

// vector<vector<Edge>>edges;
// vector<bool>inTree;
// vector<int>minCost;

// int prim(int sr, int n, int a) {
//     priority_queue<Node, vector<Node>, greater<Node>>q;
//     q.push({sr, a});
//     int result = 0;
//     int nodeCnt = 0;
//     while(!q.empty()) {
//         int u = q.top().u, cost = q.top().cost;
//         q.pop();
//         if(inTree[u]) continue;
//         inTree[u] = true;
//         result += cost;
//         nodeCnt++;
//         for(auto edge : edges[u]) {
//             int v = edge.v, w = edge.w;
//             //这里w的处理逻辑很关键
//             if(edge.w == 0) {
//                 w = a;
//             }
//             if(minCost[v] > w) {
//                 minCost[v] = w;
//                 q.push({v, w});
//             }
//         }
//         if(nodeCnt == n) break;
//     }
//     return result;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int a, b;
//     cin >> a >> b;
//     edges.resize(b+1);
//     for(int i = 1;i <= b;i++) {
//         for(int j = 1;j <= b;j++) {
//             int k;
//             cin >> k;
//             k = min(k, a);
//             edges[i].push_back({j, k});
//         }
//     }
//     int ans = INF;
//     for(int i = 1;i <= b;i++) {
//         inTree.assign(b+1, false);
//         minCost.assign(b+1, INF);
//         ans = min(ans, prim(i, b, a));
//     }
//     cout << ans;
//     return 0;
// }