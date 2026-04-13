#include<bits/stdc++.h>
using namespace std;

bool cmp(const tuple<int, int, double>&a, const tuple<int, int, double>& b) {
    return get<2>(a) > get<2>(b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<tuple<int, int, double>> jinbi(n);
    for(int i = 0;i < n;i++) {
        int m, v;
        double k;
        cin >> m >> v;
        k = v*1.0/m;
        jinbi[i] = {m, v, k};
    }
    sort(jinbi.begin(), jinbi.end(), cmp);
    double ans = 0.0, totalw = 0.0;
    for(const auto& [m, v, k] : jinbi) {
        if(totalw + m <= t) {
            totalw += m;
            ans += v;
        } else {
            ans += (t - totalw) * k;
            break;
        }
    }
    ostringstream oss;
    oss << fixed << setprecision(2) << ans;
    cout << oss.str();
    // cout << fixed << setprecision(2) << ans;
    return 0;
}