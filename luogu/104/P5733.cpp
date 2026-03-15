#include<bits/stdc++.h>
using namespace std;

int main(){
    string input;
    cin >> input;
    // cout << 'a' - 'A';
    // cout << char('A' + 32);
    for(auto it : input) {
        if(it > 'a' && it <'z') {
            cout << char(it - 'a' + 'A');
        } else {
            cout << it;
        }
    }
    return 0;
}