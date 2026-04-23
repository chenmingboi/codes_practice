#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    stack<pair<char, int>>s1;
    int len = s.length();
    vector<bool> match(105, false);
    //遇到( [ 压入栈中并压入对应的下标用来标记在匹配成功时vis=true
    //对于当前的字符，如果它是一个右括号，考察它与它左侧离它最近的未匹配的的左括号。如果该括号与之对应（即小括号匹配小括号，中括号匹配中括号），则将二者配对。如果左侧未匹配的左括号不存在或与之不对应，则其配对失败。
    //注意题目中的这个规则，如果是([)]这种情况[]是匹配的应该输出()[()]，而不是()[]()[]
    //扫描到]的时候此时它左侧最近未匹配的左括号是[所以可以匹配
    for(int i = 0;i < len;i++) {
        //只用把左括号压入栈中
        if(s1.empty()) {
            if(s[i] == '(' || s[i] == '[') {
                s1.push({s[i], i});
            }
        } else {
            auto top = s1.top();
            char top_ch = top.first, top_index = top.second;
            if((top_ch == '(' && s[i] == ')') || (top_ch == '[') && s[i] == ']') {
                match[top_index] = true, match[i] = true;
                s1.pop();
            }
            if(s[i] == '(' || s[i] == '[') {
                s1.push({s[i], i});
            }
        }
    }
    for(int i = 0;i < len;i++) {
        if(match[i]) {
            cout << s[i];
        } else {
            if(s[i] == '(' || s[i] == ')') {
                cout << "()";
            } else if(s[i] == '[' || s[i] == ']') {
                cout << "[]";
            }
        }
    }
    return 0;
}