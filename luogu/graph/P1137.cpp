#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>edges(n+1);
    vector<int>rudu(n+1, 0);
    for(int i = 0;i < m;i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        rudu[y]++;
    }
    //设置一个虚拟源节点，有到各个节点的一条边
    for(int i = 1;i <= n;i++){
        edges[0].push_back(i);
        rudu[i]++;
    } 
    vector<int>dp(n+1, 0);
    queue<int>q;
    q.push(0);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : edges[u]) {
            rudu[v]--;
            dp[v] = max(dp[v], dp[u] + 1);
            //当一个节点的入度为0的时候再push进去
            //此时dp[v]的状态是最新的状态也是最终的状态
            if(rudu[v] == 0) {
                q.push(v);
            }
        }
        
    }
    //可以尝试使用拓扑排序进行优化
    for(int i = 1;i <= n;i++) {
        cout << dp[i] << '\n';
    }
    return 0;

}