#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<int>result(11);
    for(int i = m;i <= n;i++){
        string i_str = to_string(i);
        for(auto it : i_str) {
            result[it-'0']++;
        }
        //另一种思路使用数位分离
        /*
        int t = i;
        while (t!=0){
            result[t%10]++;
            t/10;
        }
        */

    }
    for(int i = 0;i < 10;i++){
        cout << result[i] << ' ';
    }
    return 0;
}

