#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int>a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    //注意数据范围，这里要用long long
    long long result = 0;
    for(int i = 0;i < n-1;i++) {
        if(a[i] + a[i+1] > x) {
            result += a[i] + a[i+1] - x;
            if(a[i] > x) {
                a[i+1] = 0;
                a[i] = x;
            } else {
                a[i+1] = x - a[i];
            }
        }
    }
    cout << result;
    return 0;
}