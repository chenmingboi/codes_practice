#include<bits/stdc++.h>
using namespace std;

//没有连续的不平道路的时候返回true
bool judge(const vector<int>& d, const int& n) {
    for(int i = 0;i < n-1;i++) {
        if(d[i] > 0 && d[i+1] > 0) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //找到最长连续下陷深度不为0的序列进行填充
    int n, result = 0;
    cin >> n;
    vector<int>depth(n);
    for(int i = 0;i < n;i++) {
        cin >> depth[i];
    }
    /*
    第一个位置如果是 depth[0]，那至少要填这么多次
    后面每个位置如果比前一个位置更深，多出来的那部分必须“新开操作”去填
    如果不比前一个深，那它可以顺带被前面那些操作覆盖，不需要额外增加
    所以只需要统计“上升的地方”即可。
    */
    result += depth[0];
    for(int i = 1;i < n;i++) {
        if(depth[i] > depth[i-1]) {
            result += depth[i] - depth[i-1];
        }
    }
    cout << result;
    return 0;
    // while(!judge(depth, n)) {
    //     int min_d = 10001;
    //     int l = INT_MAX, r = 0;
    //     for(int i = 0;i < n-1;i++) {
    //         if(depth[i] > 0 && depth[i+1] > 0) {
    //             l = min(l, i);
    //             r = max(r, i+1);
    //             min_d = min(min_d, depth[i]);
    //             min_d = min(min_d, depth[i+1]);
    //         } else if(l != INT_MAX) {
    //             break;
    //         }
    //     }
    //     result += min_d;
    //     for(int i = l;i <= r;i++) {
    //         depth[i] -= min_d;
    //     }
    // }
    // for(int i = 0;i < n;i++) {
    //     if(depth[i] > 0) {
    //         result += depth[i];
    //     }
    // }
    // cout << result;
    return 0;
}