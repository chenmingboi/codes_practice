#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>>result(n, vector<int>(n,0));
    int num = 2;
    result[0][0] = 1;
    int hang = 0, lie = 0;
    while(num != n*n + 1){
        //向右遍历
        while(lie+1 < n && result[hang][lie+1] == 0) {
            lie++;
            result[hang][lie] = num;
            num++;
        }
        //向下遍历
        while(hang+1 < n && result[hang+1][lie] == 0) {
            hang++;
            result[hang][lie] = num;
            num++;
        }
        //向左遍历
        while(lie-1 >= 0 && result[hang][lie-1] == 0) {
            lie--;
            result[hang][lie] = num;
            num++;
        }
        //向上遍历
        while(hang-1 >= 0 && result[hang-1][lie] == 0) {
            hang--;
            result[hang][lie] = num;
            num++;
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(result[i][j] < 10) {
                cout << "  " << result[i][j];
            } else if(result[i][j] < 100) {
                cout << " " << result[i][j];
            } else {
                cout << result[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}