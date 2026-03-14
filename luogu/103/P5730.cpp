#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<string>>num(12,vector<string>(5));
    num[1][0] = num[1][4] = "XXX", num[1][1] = num[1][2] = num[1][3]= "X.X";
    num[2][0] = num[2][1] = num[2][2] = num[2][3] = num[2][4] = "..X";
    num[3][0] = num[3][2] = num[3][4] = "XXX", num[3][1] = "..X", num[3][3] = "X..";
    num[4][0] = num[4][2] = num[4][4] = "XXX", num[4][1] = num[4][3] = "..X";
    num[5][0] = num[5][1] = "X.X", num[5][2] = "XXX", num[5][3] = num[5][4] = "..X";
    num[6][0] = num[6][2] = num[6][4] = "XXX", num[6][1] = "X..", num[6][3] = "..X";
    num[7][0] = num[7][2] = num[7][4] = "XXX", num[7][1] = "X..", num[7][3] = "X.X";
    num[8][0] = "XXX", num[8][1] = num[8][2] = num[8][3] = num[8][4] = "..X";
    num[9][0] = num[9][2] = num[9][4] =  "XXX", num[9][1] = num[9][3] = "X.X";
    num[10][0] = num[10][2] = num[10][4] = "XXX", num[10][1] = "X.X", num[10][3] = "..X";
    int n;
    cin >> n;
    vector<string>result(5);
    string in;
    cin >> in;
    for(int i = 0;i < n;i++){
        result[0] += num[in[i]-'0'+1][0];
        result[1] += num[in[i]-'0'+1][1];
        result[2] += num[in[i]-'0'+1][2];
        result[3] += num[in[i]-'0'+1][3];
        result[4] += num[in[i]-'0'+1][4];
        if(i != n-1){
            result[0] += ".", result[1] += ".", result[2] += ".",
            result[3]+= ".", result[4] += ".";
        }
    }
    for(int i = 0;i < 5;i++){
        cout << result[i] << endl;
    }
    return 0;
}