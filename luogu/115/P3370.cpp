#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<string>st;
    for(int i = 0;i < n;i++) {
        string input;
        cin >> input;
        st.insert(input);
    }
    cout << st.size();
    return 0;
}