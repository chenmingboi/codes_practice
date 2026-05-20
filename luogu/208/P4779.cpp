#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m , s;
    cin >> n >> m >> s;
    //Floyd
    vector<vector<int>>dist(n+1, vector<int>(n+1, INF));
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        //这里取min是为了防止有多重边，u->v有多条边的时候取权重最小的边
        dist[u][v] = min(dist[u][v], w);
    }
    for(int i = 1;i <= n;i++) {
        //自己到自己的距离为0
        dist[i][i] = 0;
    }
    for(int k = 1;k <= n;k++) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                //dist[i][j]表示从i到j的距离，k为中间点 i->...->k->...->j
                //遍历n个中间点
                //这里加判断，表示只有i->k k->j都可达的时候才更新i->j
                if(dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        cout << dist[s][i] << ' ';
    }
    return 0;
}

// //Edge存图中的边
// struct Edge {
//     int v;
//     int w;
// };

// struct Node {
//     int dist;
//     int u;
//     //定义>的含义
//     bool operator>(const Node& a) const { return this->dist > a.dist; }
// };

// vector<int>dist;
// vector<vector<Edge>>edges;
// //visited数组用来定义该顶点是否已经被加入了已确认最短路径的节点集合
// //初始化为0，如果已经确定了最短路径，设置为1
// vector<bool>visited;
// //dijstra算法将所有节点分为两个部分，S(所有已经确定了最短路径的节点)，T（还没有确定最短路径的节点）
// //初始是将起始顶点加入S中，其中利用queue来对s中所有已经确定好最短路径但是还没有遍历其邻居节点的节点进行排序
// //当已经遍历完该节点的所有邻居节点之后就会将该节点pop掉，因为该节点已经对于将T中的节点拉入S中没有了价值
// //大致流程为，将s加入，然后遍历s的邻居，如果有更新的邻居，将该邻居加入q中，然后将s pop掉
// //循环以上流程每次取q.top()即当前已经确定的最短路径中还没有遍历其邻居节点的节点
// //直至将所有节点加入了S集合
// void dijkstra(int n, int s) {
//     //greater为小顶堆，因为定义了>的含义，所以此时会将dist最小的排在堆顶
//     priority_queue<Node, vector<Node>, greater<Node>>q;
//     dist[s] = 0;
//     q.push({0, s});//初始化dist[s] = 0;
//     while(!q.empty()) {
//         int u = q.top().u;
//         int d = q.top().dist;
//         //q.pop()要写在if(visited)前面，保证q.top能够被pop掉
//         //如果写在后面的话继续continue还是这个top元素，会导致无线循环
//         q.pop();
//         if(visited[u]) continue;
//         visited[u] = true;
//         for(auto edge : edges[u]) {
//             int v = edge.v, w = edge.w;
//             if(dist[v] > d + w) {
//                 dist[v] = d + w;
//                 q.push({dist[v], v});
//             }
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m, s;
//     cin >> n >> m >> s;
//     //这里edges相当与邻接表，所以初始化为节点数量
//     edges.resize(n+1), visited.resize(n+1, false),
//     dist.resize(n+1, 0x3f3f3f3f);
//     for(int i = 0;i < m;i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         edges[u].push_back({v, w});
//     }
//     dijkstra(n, s);
//     for(int i = 1;i <= n;i++) {
//         cout << dist[i] << ' ';
//     }
//     return 0;
// }



// struct Edge {
//     int u;
//     int v;
//     int w;
// };

// vector<Edge>edges;
// vector<int>dist;

// //对于这道题bellman_ford算法TLE，可能是由于题目中说明了不带负权，所以用Dijska会比较好
// //bellman_ford算法可以处理带有负权的图
// //bellman_ford算法的复杂度为O(mn)
// bool bellman_ford(int n, int s) {
//     dist[s] = 0;
//     bool flag = false;//标志在一个循环中有没有更新dist
//     for(int i = 1;i <= n;i++) {
//         //这个flag要在循环内重新初始化，防止上次循环的结果污染此次循环
//         flag = false;
//         //对所有的边遍历n次，其实最多在第n-1次就已经确定了最短路径
//         //bellman_ford中的第n次遍历是为了查看有没有负环，如果有负环的话
//         //第n次遍历还会更新最短路径（如果没有负环的话第n-1次遍历就已经
//         //确定了起始node到剩余n-1个节点的最短路径了
//         for(auto edge : edges) {
//             //从还没有更新的节点u更新其连接的节点没有意义
//             if(dist[edge.u] == 0x3f3f3f3f) continue;
//             if(dist[edge.v] > dist[edge.u] + edge.w) {
//                 //如果从s经过u->v这条边比原来dist[v]要小，那么更新
//                 dist[edge.v] = dist[edge.u] + edge.w;
//                 flag = true;
//             }
//         }
//         if(!flag) {
//             //当某个循环中没有更新dist的时候，说明s到达其他所有点的最短路径距离就已经求出来了
//             break;
//         }
//     }
//     //如果做了完整的n次循环，即第n次循环的时候flag仍未true此时表明有负环
//     return flag;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m, s;
//     cin >> n >> m >> s;
//     //这里dist的初始值初始化为0x3f3f3f3f
//     //即1061109567也就是约 1e9，足够表示“当前距离还没有被更新”
//     //这里不用INT_MAX的原因为在更新dist的时候需要将dist加上某个值进行比较，此时就可能会超出int范围导致溢出
//     edges.resize(m), dist.resize(n+1, 0x3f3f3f3f);
//     for(int i = 0;i < m;i++) {
//         cin >> edges[i].u >> edges[i].v >> edges[i].w;
//     }
//     bellman_ford(n, s);
//     for(int i = 1;i <= n;i++) {
//         cout << dist[i] << ' ';
//     }
// }