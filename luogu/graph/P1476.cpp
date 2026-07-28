#include<bits/stdc++.h>
using namespace std;

struct edge{
    int v;
    int w;
};
vector<vector<edge>>edges;
vector<int>rudu;


//没看懂题
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    edges.resize(n+1);
    rudu.resize(n+1, 0);
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        rudu[v]++;
    }

}