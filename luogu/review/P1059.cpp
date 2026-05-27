#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<int, bool>buckt;
    vector<int>ans;
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        if(!buckt[num]){
            buckt[num] = true;
            ans.push_back(num);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto it : ans) {
        cout << it << ' ';
    }
    return 0;
}