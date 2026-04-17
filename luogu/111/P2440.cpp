#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll count(const vector<ll>& len, const int& temp) {
    ll result = 0;
    for(auto it : len) {
        result += it / temp;
    }
    return result;
} 
int erfen(const vector<ll>& len, const int& l, const int& r, const int& k) {
    int mid = l + (r - l) / 2;
    if(l > r) {
        return -1;
    }
    if(count(len, mid) >= k) {
        //这里不必要求严格等于
        int ans = max(mid, erfen(len, mid+1, r, k));
        return ans;
    } else if(count(len, mid) < k) {
        return erfen(len, l, mid-1, k);
    }
    // } else if(count(len, mid) == k) {
        //这里问了gpt，有问题，就是可能会出现不会等于k的情况
        //比如只有一个长度为10，要求4段
        //len=3的时候只能切3端，len=2的时候切5端，不会出现等于4的情况
        //所以要记录的是切的端大于等于k且Len最长
        //再找一下还有没有更大的
        // int ans = erfen(len, mid+1, r, k);
        // if(ans == -1) {
        //     return mid;
        // } else {
        //     return ans;
        // }
    // }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ll>len(n);
    ll max_len = 0;
    for(int i = 0;i < n;i++) {
        cin >> len[i];
        max_len = max(max_len, len[i]);
    }
    //正确思路只需要知道最大的len就可以，不需要排序
    // sort(len.begin(), len.end());
    // ll result = 0;
    //先把比较小的作为划分的长度
    // for(int i = 0;i < n;i++) {
    //     int temp = 1;
    //     for(int j = i+1;j < n;j++) {
    //         temp += len[j]/len[i];
    //     }
    //     if(temp >= k) {
    //         result = max(result, len[i]);
    //     }
    // }
    // if(result != 0) {
    //     cout << result;
    // } else {
    // int result = -1;
    // for(int i = 0;i < n;i++) {
    //     //对最小的长度进行二分处理
    //     int r = len[i];
    //     int temp = erfen(len, 1, r, k);
    //     if(temp == -1) {
    //         break;
    //     }
    //     result = max(result, erfen(len, 1, r, k));
    // }
    // if(result == -1) {
    //     cout << 0;
    // } else {
    //     cout << result;
    // }
    //只需要在0-max(len)这个范围进行二分，而不是在min(len)这个范围进行二分
    int result = erfen(len, 1, max_len, k);
    if(result == -1) {
        cout << 0;
    } else {
        cout << result;
    }
    // }
    return 0;
}