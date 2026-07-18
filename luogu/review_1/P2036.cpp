#include<bits/stdc++.h>
using namespace std;

struct peiliao{
    int s;
    int b;
};    

int n;
int result = INT_MAX;

void dfs(int index, int suan, int ku, const vector<peiliao>& shicai) {
    //每一种配料都有两种选择，选或者不选
    if(index >= n) {
        //到最后再更新result，如果什么都没有选，不更新result
        if(suan == 1 && ku == 0) {
            return;
        }
        result = min(result, abs(suan-ku));
        return;
    }
    //不选
    dfs(index+1, suan, ku, shicai);
    //选
    suan *= shicai[index].s;
    ku += shicai[index].b;
    dfs(index+1, suan, ku, shicai);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<peiliao>shicai(n);
    for(int i = 0;i < n;i++) {
        cin >> shicai[i].s >> shicai[i].b;
    }
    dfs(0, 1, 0, shicai);
    cout << result;
    return 0;
}