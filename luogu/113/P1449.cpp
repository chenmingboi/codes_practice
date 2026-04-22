#include<bits/stdc++.h>
using namespace std;

int stringtoNum(string num) {
    int result = 0;
    int len = num.length();
    for(int i = 0;i < len;i++) {
        result *= 10;
        result += (num[i]- '0');
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input;
    cin >> input;
    int result = 0, len = input.length();
    stack<int>opnum;
    for(int i = 0;i < len-1;i++) {
        string num;
        while(input[i] >= '0' && input[i] <= '9') {
            num += input[i];
            i++;
        }
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            int op2 = opnum.top(); opnum.pop();
            int op1 = opnum.top(); opnum.pop();
            int temp = 0;
            char op = input[i];
            if(op == '+') {
                temp = op1 + op2;
            } else if(op == '-') {
                temp = op1 - op2;
            } else if(op == '*') {
                temp = op1 * op2;
            } else if(op == '/') {
                temp = op1 / op2;
            }
            opnum.push(temp);
        }
        if(!num.empty()) {
            opnum.push(stringtoNum(num));
        }
    }
    cout << opnum.top();
}