#include<bits/stdc++.h>
using namespace std;

unordered_map<string, string>fa;
string find(string name) {
    return (name == fa[name] ? fa[name] : find(fa[name]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input;
    string fatherName;
    while(cin >> input) {
        if(input == "$") break;
        int len = input.length();
        if(input[0] == '#') {
            fatherName = input.substr(1); //从index=1开始截到末尾
            if(fa[fatherName] == "") {
                fa[fatherName] = fatherName;
            } else {
                fa[fatherName] = find(fatherName);
            }
        } else if(input[0] == '+') {
            string childName = input.substr(1);
            fa[childName] = fatherName;
        } else if(input[0] == '?') {
            string name = input.substr(1);
            cout << name << ' ' << find(name) << endl;
        }
    }
    return 0;
}