#include<bits/stdc++.h>
using namespace std;

//简便写法参考题解一
string reverseInt(string intnum) {
    int len = intnum.length();
    string result = "";
    while(intnum[len-1] == '0') {
        len--;
        if(len == 0) break;
    }
    for(int i = len-1;i >= 0;i--) {
        result.push_back(intnum[i]);
    }
    return result;
}

string reversexiaoshu(string xiaoshu) {
    int len = xiaoshu.length();
    string result = "";
    for(int i = len-1;i >= 0;i--) {
        result.push_back(xiaoshu[i]);
    }
    while(result.back() == '0') {
        result.pop_back();
        if(result.length() == 0) break;
    }
    return result;
}

pair<string ,string> getnum(string input, char type) {
    string num1, num2;
    bool flag = false;
    for(auto it : input) {
        if(it == type) {
            flag = true;
            continue;
        }
        if(!flag) {
            num1.push_back(it);
        } else {
            num2.push_back(it);
        }
    }
    return make_pair(num1, num2); //这里也可以用{num1, num2}
}
int main() {
    string input;
    cin >> input;
    string num1, num2;
    int type = 0; //0为整数，1为小数，2为分数，3为百分数 
    if(input.find('.') != string::npos) {
        type = 1;
    } else if(input.find('/') != string::npos) {
        type = 2;
    } else if(input.find('%') != string::npos) {
        type = 3;
    }
    if(type == 0) {
        num1 = reverseInt(input);
        if(num1.length() == 0) num1="0";
        cout << num1;
    } else if(type == 1) {
        auto [num1, num2] = getnum(input, '.'); //不清楚应该赋什么类型可以用auto
        num1 = reverseInt(num1); num2 = reversexiaoshu(num2);
        if(num1.length() == 0) num1 = "0";
        if(num2.length() == 0) num2 = "0";
        cout << num1 << '.' << num2;
    } else if(type == 2) {
        auto [num1, num2] = getnum(input, '/');
        num1 = reverseInt(num1); num2 = reverseInt(num2);
        if(num1.length() == 0) num1 = "0";
        if(num2.length() == 0) num2 = "0";
        cout << num1 << '/' << num2;
    } else if(type == 3) {
        input.pop_back();
        num1 = reverseInt(input);
        if(num1.length() == 0) num1 = "0";
        cout << num1 << '%';
    }
    return 0;
}
