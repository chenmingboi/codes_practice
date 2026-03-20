#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int result = 0;
    for(int i = 0;i < n-1 ;i++) {
        if(s[i] == 'V' && s[i+1] == 'K') {
            result++;s[i] = 'X';s[i+1] = 'X';
        }
    }
    for(int i = 0;i < n-1;i++) {
        if((s[i] == 'V' && s[i+1] == 'V') || (s[i] == 'K' && s[i+1] == 'K')) {
            result++;
            break;
        }
    }
    cout << result;
    return 0;
}