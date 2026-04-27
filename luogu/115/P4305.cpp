#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //为set量身定做的一道题了属于是, emm不对，题目中不要求排序
    //可以用vector + unordered_map
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        int n;
        cin >> n;
        vector<int>nums;
        unordered_map<int, bool> appear;
        for(int j = 0;j < n;j++) {
            int num;
            cin >> num;
            if(appear[num] == false) {
                nums.push_back(num);
                appear[num] = true;
            } 
        }
        for(auto it : nums) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}