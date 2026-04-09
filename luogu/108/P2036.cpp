#include<bits/stdc++.h>
using namespace std;

// dfs
int n, result = INT_MAX;
vector<int>s(11), b(11);

void dfs(int i, int suan, int ku) {
    if(i >= n) {
        if(suan == 1 && ku == 0) {
            //没有添加配料，不更新result
            return ;
        }
        result = min(result, abs(suan-ku));
        return ;
    }
    dfs(i+1, suan*s[i], ku+b[i]);//添加下一个配料
    dfs(i+1, suan, ku); //不添加下一个配料
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> s[i] >> b[i];
    }
    dfs(0, 1, 0);
    cout << result;
    return 0;
}