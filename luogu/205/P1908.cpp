#include<bits/stdc++.h>
using namespace std;

// //写法一
// long long merge_cnt(vector<int>&a, int l, int r) {
//     if(l >= r) return 0;
//     vector<int>temp;
//     int mid = (r-l)/2 + l;
//     long long cnt = 0;
//     //左右子串各自排序
//     cnt = merge_cnt(a, l, mid) + merge_cnt(a, mid+1, r);
//     int i = l, j = mid+1;
//     while(i <= mid && j <= r) {
//         //左右子串已经有序
//         if(a[i] <= a[j]) {
//             temp.push_back(a[i]);
//             i++;
//         } else {
//             //如果a[i]>a[j]那么a[i]~a[mid]都是大于a[j]的
//             cnt += mid-i+1;
//             temp.push_back(a[j]);
//             j++;
//         }
//     }
//     while(i <= mid) {
//         temp.push_back(a[i]);
//         i++;
//     }
//     while(j <= r) {
//         temp.push_back(a[j]);
//         j++;
//     }
//     for(int k = l;k <= r;k++) {
//         a[k] = temp[k-l];
//     }
//     return cnt;
// }

//全局变量写法
long long ans = 0;
void merge_cnt(vector<int>&a, int l, int r) {
    if(l >= r) return;
    int mid = (r-l)/2 + l;
    //排序的过程中就加了逆序对数量
    merge_cnt(a, l, mid);
    merge_cnt(a, mid+1, r);
    vector<int>temp;
    int i = l, j = mid+1;
    //再添加左右两个子串之间的逆序对
    while(i <= mid && j <= r) {
        if(a[i] <= a[j]) {
            temp.push_back(a[i++]);
        } else {
            ans += mid-i+1;
            temp.push_back(a[j++]);
        }
    }
    while(i <= mid) temp.push_back(a[i++]);
    while(j <= r) temp.push_back(a[j++]);
    for(int k = l;k <= r;k++) {
        a[k] = temp[k-l];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    // cout << merge_cnt(a, 0, n-1);
    merge_cnt(a, 0, n-1);
    cout << ans;
}