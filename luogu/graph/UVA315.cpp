#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
vector<int>dfn, low;
vector<char>flag;
int tot = 0, cnt = 0;

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tot;
    int child = 0;
    for(const auto& v : edges[u]) {
        if(!dfn[v]) {
            child++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(fa != u && low[v] >= dfn[u] && !flag[u]) {
                flag[u] = true;
                cnt++;
            }
        } else if(v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(fa == u && child >= 2 && !flag[u]) {
        flag[u] = true;
        cnt++;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    while(getline(cin, line)) {
        //每个输入块的第一个数字应该是大于0的，如果是0则表示输入结束
        if(line == "0") break;
        stringstream s1(line);//将line中的内容和s1绑定
        int n;
        s1 >> n;
        edges.assign(n+1, vector<int>()), dfn.assign(n+1, 0);
        low.assign(n+1, 0), flag.assign(n+1, 0);
        tot = 0, cnt = 0;
        string line2;
        while(getline(cin, line2)) {
            if(line2 == "0") break;
            stringstream s2(line2);
            int u;
            s2 >> u;
            int v;
            while(s2 >> v) {
                edges[u].push_back(v);
                edges[v].push_back(u);
            }
        }
        for(int i = 1;i <= n;i++) {
            if(!dfn[i]) tarjan(i, i);
        }
        cout << cnt << '\n';
    }
    return 0;
}