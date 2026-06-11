// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     string s;
//     cin >> s;
//     int ansb = 0, ansg = 0, n = s.length();
//     s += "XXX";
//     for(int i = 0;i < n;i++) {
//         //用||可以判断这连续的3个字符中有没有出现boy
//         if(s[i] == 'b' || s[i+1] == 'o' || s[i+2] == 'y') ansb++;
//         if(s[i] == 'g' || s[i+1] == 'i' || s[i+2] == 'r' || s[i+3] == 'l') ansg++;
//     }
//     cout << ansb << endl << ansg;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input;
    cin >> input;
    int len = input.length();
    int cntb = 0, cntg = 0;
    for(int i = 0;i < len;i++) {
        if(i+2 < len) {
            if(input[i] == 'b' || input[i+1] == 'o' || input[i+2] == 'y') cntb++;
        }
        if(i+3 < len) {
            if(input[i] == 'g' || input[i+1] == 'i' || input[i+2] == 'r'
                || input[i+3] == 'l') {
                    cntg++;
                }
        }
    }
    cout << cntb << endl << cntg;
    return 0;
}