#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.first == b.first) ? (a.second < b.second) : a.first < b.first;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>>time(n);
    for(int i = 0;i < n;i++) {
        cin >> time[i].first;
        time[i].second = i+1; //序号
    }
    sort(time.begin(), time.end(), cmp);
    long long total_wait_time = 0.0; //可能超出int范围，使用long long
    for(int i = 0;i < n;i++) {
        cout << time[i].second << ' ';
        total_wait_time += (time[i].first) * (n-1-i);
    }
    cout << endl;
    double avg_wait_time = total_wait_time * 1.0 / n;
    ostringstream oss;
    oss << fixed << setprecision(2) << avg_wait_time;
    cout << oss.str();
    return 0;
}