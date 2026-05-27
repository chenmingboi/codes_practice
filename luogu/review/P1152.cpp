#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, first;
    cin >> n >> first;
    vector<int>ans;
    for(int i = 0;i < n-1;i++) {
        int num;
        cin >> num;
        ans.push_back(abs(num-first));
        first = num;
    }
    sort(ans.begin(), ans.end());
    for(int i = 0;i < n-1;i++) {
        if(ans[i] != i+1) {
            cout << "Not jolly";
            return 0;
        }
    }
    cout << "Jolly";
    return 0;
}