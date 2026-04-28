#include<bits/stdc++.h>
using namespace std;

//集合存集合不是用set<int, set<int>>这种是将第二个set<int>作为比较函数传进去的
//集合不支持下标访问
// set<set<int>>cankao;
vector<set<int>>cankao;
vector<bool>visited_dfs;
vector<bool>visited_bfs;

void dfs(int node) {
    // if(visited_dfs[node]) return;
    cout << node << ' ';
    visited_dfs[node] = true;
    for(auto v : cankao[node]) {
        //写在for循环中减少递归深度
        if(!visited_dfs[node]) {
            dfs(v);
        }
    }
}

void bfs(int node) {
    queue<int>q;
    q.push(node);
    //入队即标记visited
    visited_bfs[node] = true;
    while(!q.empty()) {
        int front = q.front();
        //TLE，问题在于出队的时候才标记会使得加入队列之后没有被标记visited
        //然后可能再次入队
        // if(visited_bfs[front] == false) {
        //     cout << front << ' ';
        //     visited_bfs[front] = true;
        // }
        // for(auto v : cankao[front]) {
        //     if(!visited_bfs[v]) {
        //         q.push(v);
                
        //     }
        // }
        cout << front << ' ';
        for(auto v : cankao[front]) {
            if(!visited_bfs[v]) {
                visited_bfs[v] = true;
                q.push(v);
            }
        }
        q.pop();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    visited_dfs.resize(n+1, false);
    visited_bfs.resize(n+1, false);
    cankao.resize(n+1);
    for(int i = 0;i < m;i++) {
        int x, y;
        cin >> x >> y;
        cankao[x].insert(y);
    }
    dfs(1);
    cout << endl;
    bfs(1);
    return 0;
}