#include<bits/stdc++.h>
using namespace std;

//用topo的话，可以记录每个节点的入度，输者指向赢者
//然后如果有且只有一个入度为0的节点，ans++，然后去除掉，更新连接节点的入度,如果有多个的话代表这几个都没法确定顺序，去除掉
//反复上面的循环


//floyd
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //floyd
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>>dist(n+1, vector<int>(n+1, INF));
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;//1表示a胜b
        dist[b][a] = -1;//-1表示b输给a
    }
    for(int i = 1;i <= n;i++) dist[i][i] = 1;
    for(int k = 1;k <= n;k++) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(dist[i][k] == 1 && dist[k][j] == 1) {
                    dist[i][j] = 1;
                } else if(dist[i][k] == -1 && dist[k][j] == -1) {
                    dist[i][j] = -1;
                } else {
                    //防止k == i || j 的情况 
                    // 此时dist[i][i] == 1, dist[i][j] == -1时会进入该分支
                    //要保留dist[i][j]原来的值而不是赋值为INF
                    //k == j时同理，dist[i][j] == -1 dist[j][j] == 1也会进入该分支
                    dist[i][j] = min(dist[i][j], INF);
                }
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        //begin+1是排除下标为0的空元素
        if(find(dist[i].begin()+1, dist[i].end(), INF) == dist[i].end()) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}