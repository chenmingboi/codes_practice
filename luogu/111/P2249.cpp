#include<bits/stdc++.h>
using namespace std;

int search(const int& q, const vector<int>& nums, const int& l, const int& r) {
    int pos = (l + r) / 2;
    if(l > r) {
        return -1;
    }
    if(l == r && nums[pos] != q) {
        return -1;
    }
    if(nums[pos] < q) {
        return search(q, nums, pos+1, r);
    } else if(nums[pos] > q) {
        return search(q, nums, l, pos-1);
    } else if(nums[pos] == q) {
        //查找左边有没有出现，因为可能会有多个相等的元素
        int left = search(q, nums, l, pos-1);
        if(left != -1) {
            return left;
        } else {
            return pos+1;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>nums(n);
    for(int i = 0;i < n;i++) {
        cin >> nums[i];
    }
    for(int i = 0;i < m;i++) {
        int num;
        cin >> num;
        cout << search(num, nums, 0, n-1) << ' ';
    }
    return 0;
}