#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int index = 0, num = 0;
    stack<int>st;
    while(s[index] != '@') {
        if(s[index] == '.') {
            st.push(num);
            num = 0;
        } else if(s[index] >= '0' && s[index] <= '9') {
            num *= 10;
            num += s[index] - '0';
        } else {
            int num2 = st.top(); 
            st.pop();
            int num1 = st.top();
            st.pop();
            if(s[index] == '-') {
                st.push(num1 - num2);
            } else if(s[index] == '+') {
                st.push(num1 + num2);
            } else if(s[index] == '*') {
                st.push(num1 * num2);
            } else if(s[index] == '/') {
                st.push(num1 / num2);
            }
        }
        index++;
    }
    cout << st.top();
    return 0;
}