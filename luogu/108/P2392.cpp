#include<bits/stdc++.h>
using namespace std;

//

void input(int s, vector<int>& shuzu) {
    for(int i = 0;i < s;i++) {
        cin >> shuzu[i];
    }
    return;
}

void fuxi(int s, const vector<int>& time, int& result) {
    
}

int main() {
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    vector<int>a(s1, 0), b(s2, 0), c(s3, 0), d(s4, 0);
    //在当前这一科目里，从若干题中选一些题，使得总耗时不超过k,所能达到的最大耗时
    vector<int>dp;

    input(s1, a);
    input(s2, b);
    input(s3, c);
    input(s4, d);

}