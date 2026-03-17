#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string input;
    cin >> input;
    for(auto it : input) {
        cout<< char((it-'a'+n) % 26 + 'a');
    }
    return 0;
}