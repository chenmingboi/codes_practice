#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int>count(26, 0);
    int maxH = 0;
    for(int i = 0;i < 4;i++) {
        // cin.ignore();
        string input;
        getline(cin, input);
        for(auto it : input) {
            if(it >= 'A' && it <= 'Z') {
                count[it-'A']++;
                maxH = max(count[it-'A'], maxH);
            }
        }
    }
    vector<vector<char>>map(maxH+1, vector<char>(26, ' '));
    for(int i = 0;i < maxH;i++) {
        for(int j = 0;j < 26;j++) {
            if(count[j]>=maxH-i) {
                map[i][j] = '*';
            }
        }
    }
    for(int i = 0;i < 26;i++) {
        map[maxH][i] = char('A' + i);
    }
    for(int i = 0;i < maxH+1;i++) {
        for(int j = 0;j < 26;j++) {
            if(j != 25){
                cout << map[i][j] << ' ';
            } else {
                cout << map[i][j];
            }
        }
        if(i != maxH) {
            cout << endl;
        }
    }
    return 0;
}