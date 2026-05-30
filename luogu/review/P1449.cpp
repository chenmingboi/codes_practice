#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input;
    cin >> input;
    int i = 0;
    char op = input[i];
    stack<int>num;
    int temp = 0;
    bool positive = true;
    while(op != '@') {
        if(op >= '0' && op <= '9') {
            temp *= 10;
            temp += op - '0';
        } else if(op == '.') {
            if(!positive) {
                temp = -temp;
            }
            num.push(temp);
            temp = 0;
            positive = true;
        } else if(op == '+' || op == '-' || op == '*' || op == '/') {
            int first = num.top();
            num.pop();
            int second = num.top();
            num.pop();
            if(op == '+') {
                num.push(first+second);
            } else if(op == '-') {
                num.push(second-first);
            } else if(op == '*') {
                num.push(second*first);
            } else if(op == '/') {
                num.push(second/first);
            }
        } else if(op == '-') {
            positive = false;
        }
        i++;
        op = input[i];
    }
    cout << num.top();
    return 0;
}