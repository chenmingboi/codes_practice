#include<bits/stdc++.h>
using namespace std;

long long merge_sort(int l, int r, vector<int>& a) {
    if(l >= r) return 0;
    int mid = (r-l)/2 + l;
    long long cnt = 0;
    //左子串中的逆序对+右字串中的逆序对，且该过程中分别对左子串和右子串进行了排序
    cnt = merge_sort(l, mid, a) + merge_sort(mid+1, r, a);
    //merge
    int i = l, j = mid+1;
    vector<int>temp;
    while(i <= mid && j <= r) {
        if(a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;//这里逆序对数量不变
        } else {
            //a[i] > a[j]
            temp.push_back(a[j]);
            j++;
            //因为此时左右子串有序，且a[i]此时>a[j]所以a[i]~a[mid]中的数字都大于a[j]一共mid-i+1个
            cnt += mid-i+1;
        }
    }
    while(i <= mid) temp.push_back(a[i++]);
    while(j <= r) temp.push_back(a[j++]);
    for(int k = l;k <= r;k++) {
        a[k] = temp[k-l];
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //利用merge_sort模板进行统计逆序对
    //merge_sort过程中保证左右字串分别是有序的
    //且在统计之前左右子串的相对位置是不变的，不会造成影响
    //统计合并之后已经统计过的部分相对于其他部分的相对位置也是不变的，所以也不会有影响
    //所以cnt=左子串中的逆序对+右子串中的逆序对+两侧中间的逆序对
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    cout << merge_sort(0, n-1, a);
    return 0;
}