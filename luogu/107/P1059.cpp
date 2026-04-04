#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>input;
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        if(find(input.begin(), input.end(), num) == input.end()) {
            input.push_back(num);
        }
    }
    sort(input.begin(), input.end());
    int len = input.size();
    cout << len << endl;
    for(auto it : input) {
        cout << it << ' ';
    }
    return 0;
}