#include<bits/stdc++.h>
using namespace std;

unordered_map<char, int>num_map;
string input;
void fuzhi(char var, int i) {
    if(input[i+3] >= '0' && input[i+3] <= '9') {
        num_map[var] = input[i+3] - '0';
    } else {
        num_map[var] = num_map[input[i+3]];
    }
}
int main() {
    num_map['a'] = num_map['b'] = num_map['c'] = 0;
    cin >> input;
    int len = input.length();
    for(int i = 0;i < len;i++) {
        if((input[i] == 'a' || input[i] == 'b' || input[i] == 'c') && input[i+1] == ':') {
            fuzhi(input[i], i);
        }
    }
    cout << num_map['a'] << ' ' << num_map['b'] << ' ' << num_map['c'];
}