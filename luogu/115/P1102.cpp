#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, c;
    //ans 要开成 long long
    long long ans = 0;
    cin >> n >> c;
    unordered_map<int, int>a;
    vector<int>b(n);
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        a[num]++;
        b[i] = num;
    }
    for(int i = 0;i < n;i++) {
        ans += a[b[i] + c];
    }
    cout << ans;
    return 0;
}