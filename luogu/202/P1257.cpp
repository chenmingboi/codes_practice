#include<bits/stdc++.h>
using namespace std;

double juli(const pair<int, int>& node1, const pair<int, int>& node2) {
    return sqrt(pow(node1.first-node2.first, 2) + pow(node1.second - node2.second, 2));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int,int>>nodes(n);
    for(int i = 0;i < n;i++) {
        cin >> nodes[i].first >> nodes[i].second;
    }
    double ans = juli(nodes[0], nodes[1]);
    for(int i = 0;i < n-1;i++) {
        for(int j = i + 1;j < n;j++) {
            ans = min(ans, juli(nodes[i], nodes[j]));
        }
    }
    cout << fixed << setprecision(4) << ans;
    return 0;
}