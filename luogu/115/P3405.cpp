#include<bits/stdc++.h>
using namespace std;

//这道题就是匹配name.substr(0, 2) + code 以及另一个城市的 name.substr(0, 2)(a.code) + code(a.name)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<string, int>cnt;
    long long ans = 0;
    for(int i = 0;i < n;i++) {
        string tempName, b;
        cin >> tempName >> b;
        string a = tempName.substr(0, 2);
        string key = a + b;
        string rev = b + a;
        //特殊的城市需要来自不同的州，也就是 b != a
        if(a != b) {
            cnt[key]++;
            ans += cnt[rev];
        }
    }
    cout << ans;
    return 0;
}