#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int numb = 0, numg = 0;
    string input;
    cin >> input;
    int len = input.length();
    for(int i = 0;i < len-3;i++) {
        if(input[i] == 'b' || input[i+1] == 'o' || input[i+2] == 'y') numb++;
        if(input[i] == 'g' || input[i+1] == 'i' || input[i+2] == 'r' || input[i+3] == 'l') numg++;
    }
    if(input[len-3] == 'b' || input[len-2] == 'o' || input[len-1] == 'y') numb++;
    cout << numb << endl << numg;
    return 0;
}