#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, result = 0;
    cin >> n;
    vector<int>a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    //复杂度为n^2
    result += a[0];
    // for(int i = 1;i < n;i++) {
    //     int min = INT_MAX;
    //     for(int j = i-1;j >= 0;j--) {
    //         int temp = abs(a[j] - a[i]);
    //         if(temp < min) {
    //             min = temp; 
    //         }
    //     }
    //     result += min;
    // }
    set<int>b;
    //set进行insert的时候会自动排序，默认是升序，复杂度为log n
    b.insert(a[0]);
    for(int i = 1;i < n;i++) {
        //lower_bound 它会找到第一个 >= a[i] 的数对应的迭代器
        // auto it = lower_bound(b.begin(), b.end(), a[i]);
        auto it = b.lower_bound(a[i]);
        int mn = INT_MAX;
        if(it != b.end()) {
            mn = min(mn, abs(*it - a[i]));
        }
        if(it != b.begin()) {
            it--; //判断比a[i]小的数字
            mn = min(mn, abs(*it - a[i]));
        }
        result += mn;
        b.insert(a[i]);
    }
    cout << result;
    return 0;
}