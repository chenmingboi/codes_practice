#include<bits/stdc++.h>
using namespace std;

const int MOD = 100003;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>result(n+1, 0);
    vector<int>dist(n+1, INT_MAX);
    vector<vector<int>>edges(n+1);
    vector<int>vis(n+1, false);
    for(int i = 0;i < m;i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    queue<int>q;
    q.push(1);
    dist[1] = 0;
    result[1] = 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(vis[node]) continue;
        vis[node] = true;
        for(auto v : edges[node]) {
            if(dist[node] + 1 < dist[v]) {
                dist[v] = dist[node] + 1;
                result[v] = result[node];
                q.push(v);
            } else if(dist[node] + 1 == dist[v]) {
                result[v] += result[node];
                result[v] %= MOD;
                q.push(v);
            } else {
                continue;
            }
        }
    }
    for(int i = 1;i <= n;i++) cout << result[i] << '\n';
    return 0;
}