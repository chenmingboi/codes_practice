#include<bits/stdc++.h>
using namespace std;

bool iszimu(char ch) {
    return (ch >= 'a' && ch <= 'z');
}
bool isnum(char ch) {
    return (ch >= '1' && ch <= '9');
}
bool sameType(char ch1, char ch2) {
    return (iszimu(ch1) && iszimu(ch2) || isnum(ch1) && isnum(ch2));
}
int main() {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string str, result;
    cin >> str;
    int len = str.length();
    for(int i = 0;i < len;i++) {
        result.push_back(str[i]);
        if(str[i+1] == '-' && i+1 < len) {
            if(i+2 < len && str[i+2] > str[i])
        }
    }
}