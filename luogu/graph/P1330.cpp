#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
vector<bool>vis;
//colors == 0 / 1表示两种颜色方案
vector<int>colors;
//cnt存储每一种颜色的顶点数量
vector<int>cnt(2);

bool dfs(int u) {
    vis[u] = true;
    cnt[colors[u]]++;
    for(auto v : edges[u]) {
        if(!vis[v]) {
            //把v的color染成和u不同
            colors[v] = colors[u] ^ 1;
            if(!dfs(v)) return false;
        } else {
            //如果v已经被染成和u相同的颜色，则不是二分图
            if(colors[v] == colors[u]) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, ans = 0;
    cin >> n >> m;
    //二分图
    edges.resize(n+1);
    vis.resize(n+1, false);
    colors.resize(n+1);
    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 1;i <= n;i++) {
        //发现新的连通分量
        if(!vis[i]) {
            cnt[0] = cnt[1] = 0;
            colors[i] = 0;
            if(!dfs(i)) {
                cout << "Impossible";
                return 0;
            } else {
                //选择该连通分量中颜色数量少的颜色点数
                ans += min(cnt[0], cnt[1]);
            }
        }
    }
    cout << ans;
    return 0;
}