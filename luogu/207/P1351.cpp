#include<bits/stdc++.h>
using namespace std;

const int MOD = 10007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>>edges(n+1);
    vector<int>weight(n+1);
    for(int i = 0;i < n-1;i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 1;i <= n;i++) {
        cin >> weight[i];
    }
    long long m = 0, ans = 0;
    //每个点作为中间点 u - m - v，此时m为中间点，u和v之间的距离为2
    for(int i = 1;i <= n;i++) {
        //对于邻居u,v sum = u + v
        //squaresum = u*u + v*v
        //sum^2 - squaresum = 2uv
        long long tempm = 0, tempsquaresum = 0;
        int max1 = 0, max2 = 0;
        for(auto v : edges[i]) {
            tempm += weight[v];
            tempsquaresum += (1LL * weight[v] * weight[v]) % MOD;
            if(weight[v] > max1) {
                max2 = max1;
                max1 = weight[v];
            } else if(weight[v] > max2) {
                max2 = weight[v];
            }
        }
        if(max2 != 0) {
            //至少有两个邻居
            m = max(1LL * max1 * max2, m);
            tempm = tempm * tempm - tempsquaresum;
            tempm %= MOD;
            ans += tempm;
            ans %= MOD;
        }
    }
    cout << m << ' ' << ans;
    return 0;
}
// const int MOD = 10007;
// vector<vector<int>>edges;
// vector<int>weight;
// vector<int>fa;

// void bfs(int u) {
//     queue<int>q;
//     q.push(u);
//     while(!q.empty()) {
//         int u = q.front();
//         q.pop();
//         for(auto v : edges[u]) {
//             if(v == fa[u]) continue;
//             q.push(v);
//             fa[v] = u;
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     //两个点之间的距离为2,只有两种情况u==fa[fa[v]]||v==fa[fa[u]]或者fa[u]=fa[v]
//     int n, root = 1;
//     cin >> n;
//     edges.resize(n+1), weight.resize(n+1), fa.resize(n+1);
//     for(int i = 0;i < n-1;i++) {
//         int u, v;
//         cin >> u >> v;
//         edges[u].push_back(v);
//         edges[v].push_back(u);
//     }
//     for(int i = 1;i <= n;i++) {
//         cin >> weight[i];
//         fa[i] = i;
//     }
//     for(int i = 1;i <= n;i++) {
//         root = ((edges[i].size() > edges[root].size()) ? i : root);
//     }
//     fa[root] = 0;
//     bfs(root);
//     int m = 0, ans = 0;
//     //TLE，题目中n会去到10的五次方，此时复杂度n^2太高了
//     for(int i = 1;i < n;i++) {
//         for(int j = i+1;j <= n;j++) {
//             if(fa[i] == fa[j] || i == fa[fa[j]] || j == fa[fa[i]]) {
//                 int mulw = weight[i] * weight[j];
//                 m = max(mulw, m);
//                 ans += 2 * (mulw % MOD);
//                 ans %= MOD;
//             }
//         }
//     }
//     cout << m << ' ' << ans;
//     return 0;
// }