#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long c, result = 0;
    cin >> n >> c;
    // vector<long long>a(n);
    unordered_map<long long, long long>a;
    vector<long long>tempa(n);
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        a[num]++;
        tempa[i] = num;
    }
    //复杂度为n^2，TLE
    // for(int i = 0;i < n;i++) {
    //     for(int j = i+1;j < n;j++) {
    //         if(abs(a[i]-a[j]) == c) {
    //             result++;
    //         }
    //     }
    // }
    for(int i = 0;i < n;i++) {
        result += a[tempa[i]-c];
    }
    cout << result;
    return 0;
}