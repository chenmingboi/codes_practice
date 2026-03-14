#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>>marks(n,vector<int>(3, 0));
    for(int i = 0;i < n;i++){
        cin >> marks[i][0] >> marks[i][1] >> marks[i][2];
    }
    int result = 0;
    for(int i = 0; i < n;i++) {
        for(int j = i+1;j < n;j++){
            int d1 = abs(marks[i][0] - marks[j][0]);
            int d2 = abs(marks[i][1] - marks[j][1]);
            int d3 = abs(marks[i][2] - marks[j][2]);
            int sum = abs(marks[i][0] + marks[i][1] + marks[i][2]
                - marks[j][0] - marks[j][1] - marks[j][2]);
            if(d1 <= 5 && d2 <= 5 && d3 <= 5 && sum <= 10) {
                result++;
            }
        }
    }
    cout << result;
    return 0;
}