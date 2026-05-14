#include<bits/stdc++.h>
using namespace std;

bool cmp(const int& a, const int& b) {
    return a > b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /*
    
    输入格式
第一行有两个整数 n,w。分别代表选手总数与获奖率。
第二行有 n 个整数，依次代表逐一评出的选手成绩。

输出格式
只有一行，包含 n 个非负整数，依次代表选手成绩逐一评出后，即时的获奖分数线。相邻两个整数间用一个空格分隔。
    */
    int n, w, index = 0;
    cin >> n >> w;
    //尝试利用桶计数
    vector<int>cnt(601, 0);//因为分数均为不大于600的
    for(int i = 1;i <= n;i++) {
        int score, sum = 0;
        cin >> score;
        cnt[score]++;
        index = max(1, (int)(i * float(w)/100));
        for(int j = 600;j >= 0;j--) {
            sum += cnt[j];
            if(sum >= index) {
                cout << j << ' ';
                break;
            }
        }
    }
    //TLE
    //第二个参数greater<int>表示降序排序，而如果不写的话默认为升序
    // multiset<int, greater<int>>scores; //允许重复
    // for(int i = 1;i <= n;i++) {
    //     int score;
    //     cin >> score;
    //     scores.insert(score);
    //     index = max(1, (int)(i * float(w)/100));
    //     auto it = scores.begin();
    //     advance(it, index-1);
    //     cout << *it << ' ';
    // }
    return 0;
}