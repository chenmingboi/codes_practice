#include<bits/stdc++.h>
using namespace std;

tuple<int, int, int> chaifen(int num) {
    int a1, a2, a3;
    a3 = num % 10;
    a1 = num / 100;
    a2 = (num - a1 * 100 - a3) / 10;
    return {a1, a2, a3};
}

bool judge(int a1, int a2, int a3, vector<int>&flag) {
    if(flag[a1] == 0 || flag[a2] == 0 || flag[a3] == 0 
        || a1 == a2 || a2 == a3 || a1 == a3
        || a1 == 0 || a2 == 0 || a3 == 0) return false;
    flag[a1]--, flag[a2]--, flag[a3]--;
    return true;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<tuple<int,int,int>>result;
    if(a == 0) {
        //特判，a不能为0
        cout << "No!!!";
        return 0;
    }
    for(int i = 1;i <= 9;i++) {
        for(int j = 1;j <= 9;j++) {
            for(int k = 1;k <= 9;k++) {
                if(i == j || j == k || i == k) continue;
                vector<int> flag(10, 1);
                flag[i]--, flag[j]--, flag[k]--;
                int num = i * 100 + j * 10 + k, num2 = 0, num3 = 0, a1, a2, a3;
                //判断是否能整除
                if(num * b % a != 0 || num * c % a != 0) continue;
                num2 = num * b / a, num3 = num * c / a;
                //判断是否为三位数
                if (num2 < 100 || num2 > 999 || num3 < 100 || num3 > 999) continue;
                tie(a1, a2, a3) = chaifen(num2);
                if(!judge(a1, a2, a3, flag)) continue;
                tie(a1, a2, a3) = chaifen(num3);
                if(!judge(a1, a2, a3, flag)) continue;
                result.push_back({num, num2, num3});
            }
        }
    }
    if(result.size() == 0) {
        cout << "No!!!";
    } else {
        for(auto it : result) {
            cout << get<0>(it) << ' ' << get<1>(it) << ' ' << get<2>(it) << endl;
        }
    }
    return 0;
}