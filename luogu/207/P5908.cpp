#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
vector<bool>visited;
int n, d, ans = 0;
// //dfs写法
// void dfs(int depth, int u, int fa) {
//     if(depth > d) return;
//     for(auto v : edges[u]) {
//         //防止回到父节点，题目中说只有n-1条边，所以不用考虑大环，只用防止两个元素之间的环
//         if(v == fa) continue;
//         if(depth + 1 <= d){
//             ans++;
//         }
//         dfs(depth+1, v, u);
//     }
// }
// //通用写法，防止访问已经访问过的节点（环）
// void dfs(int depth, int u){
//     if(depth > d) return;
//     visited[u] = true;
//     for(auto v : edges[u]) {
//         if(visited[v]) continue;
//         if(depth + 1 <= d) ans++;
//         dfs(depth+1, v);
//     }   
// }
// //bfs写法一
// vector<int>dist;
// void bfs(int u) {
//     queue<int>q;
//     q.push(u);
//     int depth = 0, push_cnt = 1;
//     while(!q.empty()) {
//         int u = q.front();
//         q.pop();
//         visited[u] = true;        
//         for(auto v : edges[u]) {
//             if(visited[v]) continue;
//             dist[v] = dist[u] + 1;
//             if(dist[v] <= d) ans++;
//             q.push(v);
//         }
//     }
// }
//bfs写法二
void bfs(int u) {
    queue<int>q;
    q.push(u);
    int depth = 0;
    while(!q.empty()) {
        //现在q中存储的是一层的节点
        int sz = q.size();
        depth++;
        //遍历一层的节点
        for(int i = 0;i < sz;i++) {
            int u = q.front();
            visited[u] = true;
            for(auto v : edges[u]) {
                if(visited[v]) continue;
                if(depth <= d) ans++;
                q.push(v);
            }
            q.pop();
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> d;
    edges.resize(n+1);
    visited.resize(n+1, false);
    // dist.resize(n+1, 0);
    for(int i = 1;i <= n-1;i++) {
        int u, v;
        cin >> u >> v;
        //注意这里是无向的边
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    // dfs(0, 1);
    bfs(1);
    cout << ans;
    return 0;
}