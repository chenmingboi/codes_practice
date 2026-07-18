#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    for(int i = 0;i < m;i++) {
        int q;
        cin >> q;
        //find方法是线性查找而不是二分查找，可以使用lower_bound
        // auto pos = find(nums.begin(), nums.end(), q);
        auto pos = lower_bound(nums.begin(), nums.end(), q);
        if(pos != nums.end() && *pos == q) {
            cout << pos-nums.begin()+1 << ' ';
        } else {
            cout << -1 << ' ';
        }
    }
    return 0;
}