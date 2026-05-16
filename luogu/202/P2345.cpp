#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<long long, long long>>cow(n);
    for(int i = 0;i < n;i++) {
        cin >> cow[i].first >> cow[i].second;
    }
    long long ans = 0;
    for(int i = 0;i < n-1;i++) {
        for(int j = i+1;j < n;j++) {
            ans += max(cow[i].first, cow[j].first) * abs(cow[i].second - cow[j].second);
        }
    }
    cout << ans;
    return 0;
}