#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>map(27, 0);
    map[0] = map[3] = map[6] = map[9] = map[12] = map[15] = map[19] = map[22] = 1;
    map[1] = map[4] = map[7] = map[10] = map[13] = map[16] = map[20] = map[23] = 2;
    map[2] = map[5] = map[8] = map[11] = map[14] = map[17] = map[21] = map[24] = 3;
    map[18] = map[25] = 4;
    string str;
    int result = 0;
    getline(cin, str);
    for(auto it : str) {
        if(it == ' ') {
            result++;
        } else {
            result += map[it - 'a'];
        }
    }
    cout << result;
    return 0;
}