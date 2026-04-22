#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    vector<pair<int,int>>zuoyou(n+1);//first为左边人的编号，second为右边人的编号
    zuoyou[1] = {0, 0}, zuoyou[0] = {0, 0}; zuoyou[n] = {0, 0};
    for(int i = 2;i <= n;i++) {
        int k, p;
        cin >> k >> p;
        if(p == 0) {
            int zuo = zuoyou[k].first;
            zuoyou[zuo].second = i;
            zuoyou[k].first = i;
            zuoyou[i].first = zuo, zuoyou[i].second = k;
        } else if(p == 1) {
            int you = zuoyou[k].second;
            zuoyou[you].first = i;
            zuoyou[k].second = i;
            zuoyou[i].first = k, zuoyou[i].second = you;
        }
    }
    cin >> m;
    for(int i = 0;i < m;i++) {
        int x;
        cin >> x;
        int zuo = zuoyou[x].first, you = zuoyou[x].second;
        if(zuo == -1 && you == -1) {
            continue;
        }
        zuoyou[zuo].second = you;
        zuoyou[you].first = zuo;
        zuoyou[x].first = -1, zuoyou[x].second = -1; //表示移除
    }
    int start = 0;
    for(int i = 1;i <= n;i++) {
        if(zuoyou[i].first == 0) {
            start = i; break;
        }
    }
    for(int i = start;i <= n;) {
        cout << i << ' ';
        i = zuoyou[i].second;
        if(i == 0) break;
    }
    return 0;
}