#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    double all_maxMark = 0.0;
    for(int i = 0;i < n;i++) {
        double total = 0.0, max_mark=0.0, min_mark=11.0;
        for(int i = 0;i < m;i++) {
            double mark;
            cin >> mark;
            total += mark;
            max_mark = max(mark, max_mark);
            min_mark = min(mark, min_mark);
        }
        total = (total - max_mark - min_mark) / (m-2);
        all_maxMark = max(total, all_maxMark);
    }
    cout << fixed << setprecision(2) << all_maxMark;
}