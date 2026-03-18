#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int result = 0;
    for(auto it : s) {
        if(it != ' ' && it != '\n') {
            result++;
        }
    }
    cout << result ;
    return 0;
}