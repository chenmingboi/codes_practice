// #include<bits/stdc++.h>
// using namespace std;

// //将因果链构建成图模型
// unordered_map<string, vector<string>>edges;
// unordered_map<string, int>belong;//这里的belong指的是这个人属于哪个连通分量
// unordered_map<string, int>dfn, low;
// unordered_map<string, char>instack;
// stack<string>st;
// //这里不能用set来存储，因为set会自动按照字典序进行排序
// // set<pair<string, string>>name;
// vector<pair<string, string>>name;
// int tot = 0, ssc_cnt = 0;

// void tarjan(string u) {
//     dfn[u] = low[u] = ++tot;
//     st.push(u);
//     instack[u] = 1;
//     for(auto v : edges[u]) {
//         if(!dfn[v]) {
//             tarjan(v);
//             low[u] = min(low[u], low[v]);
//         } else if(instack[v]) {
//             low[u] = min(low[u], dfn[v]);
//         }
//     }
//     if(dfn[u] == low[u]) {
//         ssc_cnt++;
//         string v;
//         do{
//             v = st.top();
//             st.pop();
//             instack[v] = 0;
//             belong[v] = ssc_cnt;
//         } while(u != v);
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     //将婚姻关系构建为从g->b的有向边，将情人关系构建为从b->g的有向边
//     //如果婚姻是不安全的则gi和bi是在同一个强连通分量里面，即从gi出发可以通过婚姻破裂，找情人这个链
//     //重新将这一条链（即强连通分量）中的人的婚姻重组
//     int n, m;
//     cin >> n;
//     //婚姻关系
//     for(int i = 0;i < n;i++) {
//         string g, b;
//         cin >> g >> b;
//         edges[g].push_back(b);
//         name.push_back({g, b});
//     }
//     cin >> m;
//     //情人关系
//     for(int i = 0;i < m;i++) {
//         string g, b;
//         cin >> g >> b;
//         edges[b].push_back(g);
//     }
//     for(auto it : name) {
//         if(!dfn[it.first]) tarjan(it.first);
//         if(!dfn[it.second]) tarjan(it.second);
//     }
//     for(auto [m1, m2] : name) {
//         if(belong[m1] == belong[m2]) {
//             cout << "Unsafe" << '\n';
//         } else {
//             cout << "Safe" << '\n';
//         }
//     }
//     return 0;
// }


//关于上面一版进行数据结构使用上的优化，这种优化适用于节点为字符串不是整数的图的构建

#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>edges;
vector<int>dfn, low, belong;
vector<char>instack;
stack<int>st;
int tot = 0, scc_cnt = 0;
//用于string->int的映射，每个string对应一个唯一的id
unordered_map<string, int>id;
int idx = 0;
int getid(const string& s) {
    if(id.find(s) == id.end()) {
        id[s] = ++idx;//从1开始编号
    }
    return id[s];
}

void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    st.push(u);
    instack[u] = 1;
    for(auto v : edges[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(instack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]) {
        scc_cnt++;
        int v;
        do{
            v = st.top();
            st.pop();
            instack[v] = 0;
            belong[v] = scc_cnt;
        } while(u != v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    vector<pair<int, int>>couples;
    edges.resize(2*n+1), dfn.resize(2*n+1), low.resize(2*n+1);
    belong.resize(2*n+1), instack.resize(2*n+1, 0);
    for(int i = 0;i < n;i++) {
        string g, b;
        cin >> g >> b;
        int gid = getid(g);
        int bid = getid(b);
        edges[gid].push_back(bid);
        couples.push_back({gid, bid});
    }
    cin >> m;
    for(int i = 0;i < m;i++) {
        string g, b;
        cin >> g >> b;
        int gid = getid(g);
        int bid = getid(b);
        edges[bid].push_back(gid);
    }
    for(int i = 1;i <= idx;i++) {
        if(!dfn[i]) tarjan(i);
    }
    for(auto [m1, m2] : couples) {
        if(belong[m1] == belong[m2]) {
            cout << "Unsafe" << '\n';
        } else {
            cout << "Safe" << '\n';
        }
    }
    return 0;
}