#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    int times = 1, len = str.length();
    string rep;
    //emmm 感觉可以用栈
    stack<int>num;
    for (int i = 0;i < len;i++) {
        string tempstr;
        if(str[i] == '[') {
            while(str[i] != ']') {
                if(str[i+1] >= '1' && str[i+1] <= '9') {
                    int mul = 0;
                    if(str[i+2] >= '1' && str[i+2] <= '9') {
                        mul = (str[i+1] - '0') * 10 + (str[i+2] - '0');
                    } else {
                        mul = str[i+1] - '0';
                    }
                    num.push(mul);
                }
                if(str[i] >= 'A' && str[i] <= 'Z') {
                    rep += str[i];
                }
                i++;
            }
        } else if(str[i] >= 'A' && str[i] <= 'Z') {
            cout << str[i];
        } 
        if(str[i] == ']') {
            for(int i = 0;i < num.top();i++) {
                tempstr += rep;
            }
            times /= num.top();
            num.pop();
        }
        if(num.empty()) {
            rep = "";
            cout << tempstr;
        } 
    }
    
    return 0;
}