#include<bits/stdc++.h>
using namespace std;

vector<int> multi(vector<int>a, int b) {
    vector<int>result;
    int len = a.size();
    for(int i = 0;i < len;i++) {
        result.push_back(a[i] * b);
    }
    for(int i = 0;i < len-1;i++) {
        if(result[i] >= 10) {
            result[i+1] += result[i] / 10;
            result[i] %= 10;
        }
    }
    while(result.back() >= 10) {
        int temp = result.back();
        result.back() %= 10;
        result.push_back(temp / 10);
    }
    return result;
}
int main() {
    int t;
    cin >> t;
    vector<int>chushi(1, 1);
    unordered_map<int, vector<int>> jiecheng;
    for(int i = 0;i < t;i++) {
        int n, a;
        cin >> n >> a;
        int flag = 0;
        vector<int>already = chushi;
        for(int j = n;j >= 1;j--) {
            if(jiecheng.count(j)) {
                flag = j;
                already = jiecheng[j];
                break;
            }
        }
        for(int j = flag + 1;j <= n;j++) {
            already = multi(already, j);
            if(!jiecheng.count(j)) {
                jiecheng[j] = already;
            }
        }
        int len = already.size(), result = 0;
        for(int j = 0;j < len;j++) {
            if(already[j] == a) {
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}