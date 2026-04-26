#include<bits/stdc++.h>
using namespace std;

//完美二叉树一般情况下推荐使用数组的形式来存储

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, total, tempn;
    cin >> n;
    total = pow(2, n), tempn = n;
    vector<pair<int, int>>cap(total);
    for(int i = 0;i < total;i++) {
        int capi;
        cin >> capi;
        cap[i] = {capi, i+1};
    }
    while(cap.size() != 2) {
        int len = pow(2, tempn);
        for(int i = 0,j = 1, k = 0;i < len-1,j < len;k++) {
            cap[k] = (cap[i].first > cap[j].first) ? cap[i] : cap[j];
            i += 2, j += 2;
        }
        cap.resize(len/2);
        tempn--;
    }
    cout << ((cap[0].first > cap[1].first) ? cap[1].second : cap[0].second);
    return 0;
}