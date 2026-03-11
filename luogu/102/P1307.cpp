#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 0) {
        cout << 0;
        return 0;
    }
    string n_str = to_string(n);
    string result = "";
    if(n < 0) {
        result.push_back('-');
    }
    int len = n_str.length();
    for(int i = len-1;i >= 0;i--){
        if(n_str[i]=='0') {
            n_str.pop_back();
        } else {
            break;
        }
    }
    int len_new = n_str.length();
    for(int i = len_new-1;i >= 0;i--){
        if(n_str[i] != '-') {
            result.push_back(n_str[i]);
        }
    }
    cout << result;
    return 0;
}