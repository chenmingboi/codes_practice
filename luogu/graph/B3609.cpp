#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
vector<int>dfn, low;
int scc_cnt = 0, tot = 0;//tot表示发现此节点的时间，scc_cnt表示连通分支数量
vector<bool>inStack;
vector<int>scc_id;//scc_id表示每个节点所属的scc序号
vector<vector<int>>belong;//表示某个连通分支中的节点序号
stack<int>st;

void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    st.push(u);
    inStack[u] = true;
    for(auto v : edges[u]) {
        if(!dfn[v]) {
            //当dfn还没有被赋值的时候即此时v还没有被访问过，v是u的子节点
            tarjan(v);//递归访问未访问的子节点
            low[u] = min(low[u], low[v]);//此时v已经遍历完tarjan(v)已经return
            //检查v的子树是否能追溯到更早的祖先，此时low[v]已经更新好了，所以用low[v]更新low[u]
        } else if(inStack[v]) {
            //在栈里面，即v是u的父节点，由于此时v还没有遍历完，low[v]还没有更新好，所以用dfn[v]
            //想一想，u是v的子节点都还没有遍历完，所以v作为父节点肯定还没有回溯，即low[v]肯定还没有更新
            low[u] = min(low[u], dfn[v]);
        }
    }
    //此时u为所在连通分量中第一个被访问的顶点（即是该SCC的根）
    //此时将栈中从栈顶到u的所有顶点弹出，它们共同构成了一个强连通分量
    if(low[u] == dfn[u]) {
        scc_cnt++;
        int v;
        do{
            v = st.top();
            st.pop();
            scc_id[v] = scc_cnt;
            //出栈
            inStack[v] = false;
            belong[scc_cnt].push_back(v);
        }while(u != v);
        sort(belong[scc_cnt].begin(), belong[scc_cnt].end());
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    edges.resize(n+1);
    dfn.resize(n+1, 0);
    low.resize(n+1, 0);
    inStack.resize(n+1, false);
    belong.resize(n+1);
    scc_id.resize(n+1);
    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        edges[u].emplace_back(v);
    }
    //图可能不连通，所以需要遍历所有顶点
    for(int i = 1;i <= n;i++) {
        if(!dfn[i]) {
            tarjan(i);
        }
    }
    cout << scc_cnt << '\n';
    vector<int>printed(n+1, false);
    for(int i = 1;i <= n;i++) {
        int scc = scc_id[i];
        if(printed[scc]) continue;
        printed[scc] = true;
        for(auto node : belong[scc]) cout << node << ' ';
        cout << '\n';
    }
    return 0;
}