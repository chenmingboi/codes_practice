#include<bits/stdc++.h>
using namespace std;

//第一眼看到这道题，没什么思路（好吧，审错题了，第一眼看成最少需要的动作次数了，其实只需要判断
//第几个操作可以完成就行了

bool judge(int n, vector<vector<char>>input, vector<vector<char>>target) {
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(input[i][j] != target[i][j]) return false;
        }
    }
    return true;
}
//顺时针旋转90度
vector<vector<char>> circle90(int n, vector<vector<char>>input) {
    vector<vector<char>>temp(n, vector<char>(n));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            temp[i][j] = input[n-1-j][i];
        }
    }
    return temp;
}

//顺时针旋转180度(即旋转两次90度)
vector<vector<char>> circle180(int n, vector<vector<char>>input) {
    vector<vector<char>>temp = circle90(n, input);
    return circle90(n, temp);
}

//顺时针旋转270度（180+90）
vector<vector<char>> circle270(int n, vector<vector<char>>input) {
    vector<vector<char>>temp = circle180(n, input);
    return circle90(n, temp);
}

//反射
vector<vector<char>> fanshe(int n, vector<vector<char>>input) {
    vector<vector<char>>temp(n, vector<char>(n));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            temp[i][j] = input[i][n-1-j];
        }
    }
    return temp;
}

//组合
bool zuhe(int n, vector<vector<char>>input, vector<vector<char>>target){
    vector<vector<char>>temp = fanshe(n, input);
    if(judge(n, circle90(n, temp), target) || 
        judge(n, circle180(n, temp), target) ||
        judge(n, circle270(n, temp), target)) {
            return true;
        } else {
            return false;
        }
}

int main(){
    int n;
    cin >> n;
    vector<vector<char>>input(n, vector<char>(n));
    vector<vector<char>>target(n, vector<char>(n));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> input[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> target[i][j];
        }
    }
    if(judge(n, circle90(n, input), target)) {
        cout << 1;
    } else if(judge(n, circle180(n, input), target)) {
        cout << 2;
    } else if(judge(n, circle270(n, input), target)) {
        cout << 3;
    } else if(judge(n, fanshe(n, input), target)) {
        cout << 4;
    } else if(zuhe(n, input, target)){
        cout << 5;
    } else if(judge(n, input, target)) {
        cout << 6;
    } else {
        cout << 7;
    }
    return 0;
}