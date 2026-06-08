#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

//kruskal
struct Edge{
    int u;
    int v;
    int w;
};

bool comp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

vector<Edge>edges;
vector<int>fa;
vector<int>weight;

int findfa(int x) {
    return ((x == fa[x]) ? fa[x] : fa[x] = findfa(fa[x]));
}

bool merge(int x, int y) {
    int fax = findfa(x), fay = findfa(y);
    if(fax == fay) return false;
    if(weight[fax] > weight[fay]) {
        fa[fay] = fax;
    } else {
        if(weight[fax] == weight[fay]) weight[fay]++;
        fa[fax] = fay;
    }
    return true;
}

int kruskal(int n) {
    sort(edges.begin(), edges.end(), comp);
    int ans = 0;
    int edgeCnt = 0;
    for(auto edge : edges) {
        int u = edge.u, v = edge.v, w = edge.w;
        if(merge(u, v)) {
            edgeCnt++;
            ans += w;
        }
        if(edgeCnt == n-1) break;
    }
    if(edgeCnt != n-1) {
        return -1;
    } else {
        return ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    edges.resize(m), fa.resize(n+1);
    weight.resize(n+1, 1);
    for(int i = 1;i <= n;i++) fa[i] = i;
    for(int i = 0;i < m;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }
    int ans = kruskal(n);
    if(ans == -1) {
        cout << "orz";
    } else {
        cout << ans;
    }
    return 0;
}
// //prim
// struct Edge {
//     int v;
//     int w;
// };

// struct Node{
//     int u;
//     //这里的d表示的是u的父节点到u的最小距离
//     //即连通u 需要花费的最小cost
//     int d;
//     bool operator>(const Node& other) const {
//         return d > other.d;
//     }
// };

// vector<vector<Edge>>edges;
// vector<bool>inTree;
// //这里的dist用来记录节点u的所有父节点到达u的最小distance
// vector<int>dist;

// int prim(int n) {
//     int ans = 0;
//     int nodeCnt = 0;
//     priority_queue<Node, vector<Node>, greater<Node>>q;
//     q.push({1, 0});
//     dist[1] = 0;
//     while(!q.empty()) {
//         if(nodeCnt == n) break;
//         int u = q.top().u, d = q.top().d;
//         q.pop();
//         if(inTree[u]) continue;
//         inTree[u] = true;
//         ans += d;
//         nodeCnt++;
//         for(auto edge : edges[u]) {
//             int v  = edge.v, w = edge.w;
//             if(dist[v] > w) {
//                 dist[v] = w;
//                 q.push({v, dist[v]});
//             }
//         }
//     }
//     if(nodeCnt != n) {
//         return -1;
//     } else {
//         return ans;
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m;
//     cin >> n >> m;
//     edges.resize(n+1), inTree.resize(n+1, false);
//     dist.resize(n+1, INF);
//     for(int i = 0;i < m;i++) {
//         int x, y, z;
//         cin >> x >> y >> z;
//         edges[x].push_back({y, z});
//         edges[y].push_back({x, z});
//     }
//     int ans = prim(n);
//     if(ans == -1) {
//         cout << "orz";
//     } else {
//         cout << ans;
//     }
//     return 0;
// }

// //kruskal
// struct Edge{
//     int u;
//     int v;
//     int w;
// };

// bool comp(const Edge& a, const Edge& b) {
//     return a.w < b.w;
// }

// vector<Edge>edges;
// vector<int>fa;
// vector<int>weight;

// int findfa(int x) {
//     return ((x == fa[x]) ? fa[x] : fa[x] = findfa(fa[x]));
// }

// bool merge(int u, int v) {
//     int fau = findfa(u), fav = findfa(v);
//     if(fau == fav) return false;
//     if(weight[fau] < weight[fav]) {
//         fa[fau] = fav;
//     } else {
//         if(weight[fau] == weight[fav]) {
//             weight[fau]++;
//         }
//         fa[fav] = fau;
//     }
//     return true;
// }

// int kruskal(int n) {
//     sort(edges.begin(), edges.end(), comp);
//     int ans = 0;
//     int edgeCnt = 0;
//     //这里不用写为n-1个循环，这里循环一遍edges集合就行
//     // for(int i = 1;i < n;i++) {
//     for(auto edge : edges) {
//         int u = edge.u, v = edge.v, w = edge.w;
//         if(merge(u, v)) {
//             edgeCnt++;
//             ans+= w;
//         }
//         if(edgeCnt == n-1) break;
//     }
//     if(edgeCnt != n-1) {
//         return -1;
//     } else {
//         return ans;
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m;
//     cin >> n >> m;
//     edges.resize(m), fa.resize(n+1), weight.resize(n+1, 1);
//     for(int i = 1;i <= n;i++) fa[i] = i;
//     for(int i = 0;i < m;i++) {
//         int x, y, z;
//         cin >> x >> y >> z;
//         edges[i] = {x, y, z};
//     }
//     int ans = kruskal(n);
//     if(ans == -1) {
//         cout << "orz";
//     } else {
//         cout << ans;
//     }
//     return 0;
// }

// //prim
// struct Edge{
//     int v;
//     int w;
// };

// struct Node{
//     int u;
//     //这里的d表示上一个节点到该节点u的距离大小
//     int d;
//     bool operator>(const Node& other) const {
//         return d > other.d;
//     }
// };

// vector<vector<Edge>>edges;
// vector<bool>inTree;
// //cost[i]表示把节点i加入最小生成树的cost
// //(即把节点i加入最小生成树需要加入的最小边权)
// vector<int>cost;

// int prim(int n) {
//     priority_queue<Node, vector<Node>, greater<Node>>q;
//     q.push({1, 0});
//     int ans = 0;
//     int nodeCnt = 0;
//     while(!q.empty()) {
//         int u = q.top().u, d = q.top().d;
//         q.pop();
//         if(inTree[u]) continue;
//         inTree[u] = true;
//         nodeCnt++;
//         ans += d;
//         for(auto edge : edges[u]) {
//             int v = edge.v, w = edge.w;
//             //这里如果连接v的边的权重大于已知的某一条边，此时就不再添加
//             if(cost[v] > w) {
//                 cost[v] = w;
//                 q.push({v, w});
//             }
//         }
//     }
//     if(nodeCnt == n) {
//         return ans;
//     } else {
//         return -1;
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m;
//     cin >> n >> m;
//     edges.resize(n+1);
//     inTree.resize(n+1, false);
//     cost.resize(n+1, INF);
//     for(int i = 0;i < m;i++) {
//         int x, y, z;
//         cin >> x >> y >> z;
//         edges[x].push_back({y, z});
//         edges[y].push_back({x, z});
//     }
//     int ans = prim(n);
//     if(ans == -1) {
//         cout << "orz" << '\n';
//     } else {
//         cout << ans;
//     }
//     return 0;
// }





// // prim 类似与dijkstra
// struct Edge {
//     int v;
//     int w;
// };

// struct Node{
//     //这里的d不同于dijkstra中的d的含义
//     //这里的d是u的neighbor到u的边的权重
//     //最小生成树中要添加u 很明显是要从u的neighbor连到u
//     //然后从neighbor到u的边的权重中挑一个最小的添加到最小生成树边中
//     int u;
//     int d;
//     bool operator>(const Node& other) const {
//         return d > other.d;
//     }
// };

// vector<vector<Edge>>edges;
// vector<bool>inTree;
// vector<int>dist;

// int prim(int n) {
//     int result = 0;
//     int nodeCnt = 0;
//     priority_queue<Node, vector<Node>, greater<Node>>q;
//     q.push({1, 0});
//     while(!q.empty()) {
//         int u = q.top().u, d = q.top().d;
//         q.pop();
//         if(inTree[u]) continue;
//         inTree[u] = true;
//         nodeCnt++;
//         result += d;
//         for(auto edge : edges[u]) {
//             int v = edge.v, w = edge.w;
//             //这一步的意义在于对于所有的neighbor到v的边
//             //对于已经加入q的比较小的边的权重可以用来作为bar
//             //这个bar用来拒绝之后neighbor到v比该边权重更大的边加入q
//             //减少无意义的push和pop
//             if(dist[v] > w) {
//                 dist[v] = w;
//                 q.push({v, w});
//             }
//             // q.push({v, w});
//         }
//     } 
//     //这里也可以通过添加nodeCnt来优化
//     // for(int i = 1;i <= n;i++) {
//     //     //-1表示有的点没有在最小生成树中，即表示该图不连通
//     //     if(!inTree[i]) return -1;
//     // }
//     if(nodeCnt == n) {
//         return result;
//     } else {
//         return -1;
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m;
//     cin >> n >> m;
//     inTree.resize(n+1, false);
//     edges.resize(n+1);
//     dist.resize(n+1, INF);
    
//     for(int i = 0;i < m;i++) {
//         int x, y, z;
//         cin >> x >> y >> z;
//         edges[x].push_back({y, z});
//         edges[y].push_back({x, z});
//     }
//     int ans = prim(n);
//     if(ans == -1) {
//         cout << "orz";
//     } else {
//         cout << ans;
//     }
//     return 0;
// }


// // kruskal 类似与bellman_ford

// struct Edge {
//     int u;
//     int v;
//     int w;
// };

// bool comp(const Edge& a, const Edge& b) {
//     return a.w < b.w;
// }

// vector<int>fa;
// vector<int>weight;
// vector<Edge>edges;

// int findfa(int x) {
//     return ((x == fa[x]) ? fa[x] : fa[x] = findfa(fa[x]));
// }

// bool merge(int x, int y) {
//     int fax = findfa(x), fay = findfa(y);
//     if(fax == fay) return false;
//     if(weight[fax] > weight[fay]) {
//         fa[fay] = fax;
//     } else {
//         if(weight[fax] == weight[fay]) weight[fay]++;
//         fa[fax] = fay;
//     }
//     return true;
// }

// int kruskal(int n) {
//     int result = 0;
//     int edgeCnt = 0;
//     sort(edges.begin(), edges.end(), comp);
//     for(auto edge : edges) {
//         int u = edge.u, v = edge.v, w = edge.w;
//         if(merge(u, v)) {
//             result += w;
//             edgeCnt++;
//         }
//         //这里可以添加一个判断条件来优化，提前终止循环
//         if(edgeCnt == n-1) break;
//     }
//     //最小生成树的边数为n-1
//     if(edgeCnt == n-1) {
//         return result;
//     } else {
//         return -1;
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m;
//     cin >> n >> m;
//     fa.resize(n+1), weight.resize(n+1, 1);
//     edges.resize(m);
//     for(int i = 1;i <= n;i++) fa[i] = i;
//     for(int i = 0;i < m;i++) {
//         int x, y, z;
//         cin >> x >> y >> z;
//         //这里edge不同于prim中的edge
//         //这里的edge是双向边，因为在遍历的时候是遍历的边
//         //然后添加边对应的两个节点
//         edges[i] = {x, y, z};
//     }
//     int ans = kruskal(n);
//     if(ans == -1) {
//         cout << "orz";
//     } else {
//         cout << ans;
//     }
//     return 0;
// }