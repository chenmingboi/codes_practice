#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<int, pair<int, int>>position; //数字：行，列
    vector<vector<int>> huanfang(n, vector<int>(n, 0));
    position[1] = {0, n/2};
    huanfang[0][n/2] = 1;
    for(int i = 2; i <= n*n;i++){
        int hang = position[i-1].first;
        int lie = position[i-1].second;
        if(hang == 0 && lie != n-1){
            position[i].first = n-1;
            position[i].second = lie+1;
            huanfang[position[i].first][position[i].second] = i;
        } else if(lie == n-1 && hang != 0) {
            position[i].first = hang -1;
            position[i].second = 0;
            huanfang[position[i].first][position[i].second] = i;
        } else if(hang == 0 && lie == n-1) {
            position[i].first = hang + 1;
            position[i].second = lie;
            huanfang[position[i].first][position[i].second] = i;
        } else if(hang != 0 && lie != n - 1) {
            if(huanfang[hang-1][lie+1] == 0) {
                position[i].first = hang - 1;
                position[i].second = lie + 1;
                huanfang[hang-1][lie+1] = i;
            } else {
                position[i].first = hang + 1;
                position[i].second = lie;
                huanfang[hang+1][lie] = i;
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cout << huanfang[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}