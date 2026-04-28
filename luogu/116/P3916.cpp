#include<bits/stdc++.h>
using namespace std;

//推荐使用反图写法，反向染色
vector<vector<int>>rev_edges;
vector<int>ans;

void dfs(int u, int value) {
    //如果这个点已经有答案了，说明它已经被更大的编号染过了，不需要再处理。
    if(ans[u] != 0) return;
    //当前从 value 这个大编号点反向走到了 u，说明原图中 u 可以到达 value。
    ans[u] = value;
    //继续反向走，把所有“原图中能到达 value 的点”都找出来。
    for(auto v : rev_edges[u]) {
        dfs(v, value);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    rev_edges.resize(n+1), ans.resize(n+1);
    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        rev_edges[v].push_back(u); //原来u->v ,反向图中v->u
    }
    for(int i = n;i >= 1;i--) {
        dfs(i, i);
    }
    for(int i = 1;i <= n;i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}

// vector<vector<int>>edges;
// //尝试用vector<int>来记录最大值
// vector<bool>vis;
// vector<int>ans;
// int n;
// int dfs(int u) {
//     if(vis[u]) return ans[u];
//     vis[u] = true;
//     for(auto v : edges[u]) {
//         if(!vis[v]) {
//             ans[u] = max(ans[u], dfs(v));
//         }
//     }
//     return ans[u] = max(ans[u], u);
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int m;
//     cin >> n >> m;
//     edges.resize(n+1), ans.resize(n+1), vis.resize(n+1, false);
//     for(int i = 0;i < m;i++) {
//         int u, v;
//         cin >> u >> v;
//         edges[u].push_back(v);
//     }
//     for(int i = 1;i <= n;i++) {
//         if(ans[i] == n) continue;
//         dfs(i);
//     }
//     for(int i = 1;i <= n;i++) {
//         cout << ans[i] << ' ';
//     }
//     return 0;
// }