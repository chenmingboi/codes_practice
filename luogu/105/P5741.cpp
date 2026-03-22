#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<string, string>>result;
    int n;
    cin >> n;
    vector<string>student_name(n);
    vector<vector<int>>score(n, vector<int>(4,0));
    for(int i = 0;i < n;i++) {
        cin >> student_name[i];
        cin >> score[i][0] >> score[i][1] >> score[i][2];
        int total = score[i][0] + score[i][1] + score[i][2];
        score[i][3] = total;
    }
    for(int i = 0;i < n-1;i++) {
        for(int j = i+1;j < n;j++) {
            if(abs(score[i][0] - score[j][0]) <= 5 && 
                abs(score[i][1] - score[j][1]) <= 5 &&
                abs(score[i][2] - score[j][2]) <= 5 &&
                abs(score[i][3] - score[j][3]) <= 10) {
                    result.push_back({student_name[i], student_name[j]});
                }
        }
    }
    for(auto it : result) {
        cout << it.first << ' ' << it.second << endl;
    }
    return 0;
}