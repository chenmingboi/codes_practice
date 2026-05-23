#include<bits/stdc++.h>
using namespace std;


//prime
//prime算法和Dijkstra算法的核心逻辑一样都是将顶点分为两个集合，一个是已经加入，一个是还没有加入的
const int INF = 0x3f3f3f3f;

struct Edge{
    int v;
    int w;
};

struct Node{
    int u;
    //这里的dis表示的是上个节点到u的距离（即v->u边的权重）
    int dis;
    bool operator>(const Node& b) const { return dis > b.dis; }
};

vector<vector<Edge>>edges;
vector<int>dis;
vector<bool>vis;

long long prime(int n) {
    priority_queue<Node, vector<Node>, greater<Node>> q;
    q.push({1, 0});
    long long nodeCnt = 0, ans = 0;
    while(!q.empty()) {
        if(nodeCnt == n) break;
        int u = q.top().u, d = q.top().dis;
        q.pop();
        //如果已经添加在了最小生成树中跳过
        if(vis[u]) continue;
        vis[u] = true;
        nodeCnt++;
        //添加上个节点到该节点的边权重
        ans += d;
        for(const auto& edge : edges[u]) {
            int w = edge.w, v = edge.v;
            //这一步的意义在于，如果有多个顶点指向v,则会筛掉一部分比已经push进q中的边的权重更大的
            //减少无意义的遍历以及push操作
            //eg 1->2 w = 3, 3->2 w = 4,当已经添加1->2 {2, 3}的时候dis[2]被更新为3此时就不会添加{2, 4}
            if(dis[v] > w) {
                dis[v] = w;
                q.push({v, w});
            }
        }
    }
    if(nodeCnt == n) {
        return ans;
    } else {
        return -1;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    edges.resize(n+1), dis.resize(n+1, INF), vis.resize(n+1, false);
    for(int i = 0;i < m;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        //双向边
        edges[x].push_back({y, z});
        edges[y].push_back({x, z});
    }
    long long ans = prime(n);
    if(ans == -1) {
        cout << "orz";
    } else {
        cout << ans;
    }
    return 0;
}


// //kruskal
// struct Edge{
//     int u;
//     int v;
//     int w;
// };
// vector<int>fa, weight;
// vector<Edge>edges;

// bool comp(const Edge& a, const Edge& b) {
//     return a.w < b.w;
// }

// int findFa(int u) {
//     return ((u == fa[u]) ? fa[u] : (fa[u] = findFa(fa[u])));
// }

// bool merge(int u, int v) {
//     //这里应该调用findFa,否则拿到的可能不是根节点，路径压缩后也可能判断错误。
//     int fau = findFa(u), fav = findFa(v);
//     if(fau == fav) return false;
//     if(weight[fau] < weight[fav]) {
//         //将fau合并到fav分支中
//         fa[fau] = fav;
//     } else {
//         //将fav合并到fau中
//         if(weight[fau] == weight[fav]) {
//             weight[fau]++;
//         }
//         fa[fav] = fau;
//     }
//     return true;
// }

// long long kruskal(int n) {
//     long long edgeCnt = 0, ans = 0;
//     //将edges边的权重从小到大排序，采用贪心的算法
//     sort(edges.begin(), edges.end(), comp);
//     for(const auto& edge : edges) {
//         int u = edge.u, v = edge.v, w = edge.w;
//         if(merge(u, v)) {
//             //如果u,v不在一个联通集合中则将两个节点合并
//             //在一个联通集合中则不合并，因为那样的话会导致环且对于扩展点数毫无作用
//             edgeCnt++, ans+= w;
//         }
//         //如果边数达到了n-1说明已经构造好了一颗最小生成树
//         if(edgeCnt == n-1) {
//             break;
//         }
//     }
//     //如果能构造出最小生成树则输出ans,如果该图不联通即没有办法构造出最小生成树返回-1
//     if(edgeCnt == n-1) {
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
//     weight.resize(n+1, 1), edges.resize(2*m), fa.resize(n+1);
//     for(int i = 1;i <= n;i++) fa[i] = i;
//     for(int i = 0;i < m;i++) {
//         int x, y, z;
//         cin >> x >> y >> z;
//         //题中说明是无向边，所以要添加两条) no, 这里没必要添加两条
//         //因为无论是有向边还是无向边，权重一样，sort的是权重
//         //添加的时候是把边的两端定点都添加进去了，有向边和无向边都一样
//         // edges[2*i] = {x, y, z};
//         // edges[2*i + 1] = {y, x, z};
//         edges[i] = {x, y, z};
//     }
//     long long ans = kruskal(n);
//     if(ans != -1) {
//         cout << ans;
//     } else {
//         cout << "orz";
//     }
//     return 0;
// }