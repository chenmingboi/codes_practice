#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long c, result = 0;
    cin >> n >> c;
    vector<long long>a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    //复杂度为n^2，TLE
    //尝试用二分，分为左，中，右
    for(int i = 0;i < n;i++) {
        for(int j = i+1;j < n;j++) {
            if(abs(a[i]-a[j]) == c) {
                result++;
            }
        }
    }
    cout << result;
    return 0;
}