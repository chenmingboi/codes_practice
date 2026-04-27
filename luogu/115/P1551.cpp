#include<bits/stdc++.h>
using namespace std;

vector<int>fa, ra;
//参考教程 https://zhuanlan.zhihu.com/p/93647900
//rank表示集合的秩，fa表示每个集合中的父节点，初始每个节点都为一个集合且父节点是自己
//初始秩为1
void init(int n) {
    for(int i = 1;i <= n;i++) {
        fa[i] = i; 
        ra[i] = 1;
    }
}

int find(int x) {
    //找x所属集合中的代表元素，在找的过程中同时更新搜索路径上对应节点的fa
    return (x == fa[x] ? fa[x] : find(fa[x]));
}

void merge(int i, int j) {
    int x = find(i), y = find(j);//找到i 和 j所属集合的代表元素
    if(x == y) return;
    //选择将秩小的集合合并到秩大的集合下面，更新fa和ra
    if(ra[x] < ra[y]) {
        fa[x] = y;
    } else {
        if(ra[x] == ra[y]) {
            ra[x]++;
        }
        fa[y] = x;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, p;
    cin >> n >> m >> p;
    ra.resize(n+1), fa.resize(n+1);
    init(n);
    for(int i = 0;i < m;i++) {
        int mi, mj;
        cin >> mi >> mj;
        int fai = find(mi), faj = find(mj);
        if(fai != faj) {
            merge(fai, faj);
        }
    }
    for(int i = 0;i < p;i++) {
        int pi, pj;
        cin >> pi >> pj;
        int fai = find(pi), faj = find(pj);
        if(fai == faj) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}