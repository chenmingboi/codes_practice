#include<bits/stdc++.h>
using namespace std;

void judge(int& score_1, int& score_2, vector<string>& result, int point) {
    if((score_1 >= point && score_1 >= score_2+2) ||
        (score_2 >= point && score_2 >= score_1+2)) {
        result.push_back(to_string(score_1) + ':' + to_string(score_2));
        score_1 = 0, score_2 = 0;
    }
    return;
}
int main() {
    char c;
    int score_a = 0, score_b = 0, score_c = 0, score_d = 0;
    vector<string>result_1, result_2;
    bool end = false;
    while(cin >> c) {
        if(c == 'E') {
            end = true;
            break;
        } else if(c == 'W') {
            score_a++; score_c++;
            judge(score_a, score_b, result_1, 11);
            judge(score_c, score_d, result_2, 21);
        } else if(c == 'L') {
            score_b++; score_d++;
            judge(score_a, score_b, result_1, 11);
            judge(score_c, score_d, result_2, 21);
        }
    }
    //注意一局比赛结束后下一句比赛立即开始，所以0:0也需要输出，所以这里直接添加最后没有push进一轮的部分就行
    if(end) {
        result_1.push_back(to_string(score_a) + ':' + to_string(score_b));
        result_2.push_back(to_string(score_c) + ':' + to_string(score_d));
    }
    for(auto it : result_1) {
        cout << it << endl;
    }
    cout << endl;
    for(auto it : result_2) {
        cout << it << endl;
    }
    return 0;
}