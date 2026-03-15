#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>>result(n);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j <= i;j++){
            if(j == 0 || j == i) {
                result[i].push_back(1);
            } else {
                result[i].push_back(result[i-1][j] + result[i-1][j-1]);
            }
        }
    }
    for(auto it : result){
        for(auto item : it){
            cout << item << ' ';
        }
        cout << endl;
    }
    return 0;
}