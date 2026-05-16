#include<bits/stdc++.h>
using namespace std;

void merge_sort(int l, int r, vector<int>& a) {
    if(l >= r) return;
    int mid = (r-l)/2 + l;
    //先把从mid分开的左右两部分进行排序，保证左右子串是有序的
    merge_sort(l, mid, a);
    merge_sort(mid+1, r, a);
    //左右子串排好序后进行合并
    vector<int>temp;
    int i = l, j = mid+1;
    while(i <= mid && j <= r) {
        if(a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(a[j]);
            j++;
        }
    }
    while(i <= mid) temp.push_back(a[i++]);
    while(j <= r) temp.push_back(a[j++]);
    for(int k = l;k <= r;k++) {
        a[k] = temp[k-l];
    }
    return;
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
    merge_sort(0, n-1, a);
    for(int i = 0;i < n;i++) {
        cout << a[i] << ' ';
    }
    return 0;
}