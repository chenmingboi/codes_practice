#include<bits/stdc++.h>
using namespace std;

//可以用二维数组存储结果来简化代码行数
int judge(int a, int b) {
    // 0：平局，1：a胜，2：a输
    if(a == 0) {
        if(b == 0) {
            return 0;
        } else if(b == 1) {
            return 2;
        } else if(b == 2) {
            return 1;
        } else if(b == 3) {
            return 1;
        } else if(b == 4) {
            return 2;
        }
    } else if(a == 1) {
        if(b == 0) {
            return 1;
        } else if(b == 1) {
            return 0;
        } else if(b == 2) {
            return 2;
        } else if(b == 3) {
            return 1;
        } else if(b == 4) {
            return 2;
        }
    } else if(a == 2) {
        if(b == 0) {
            return 2;
        } else if(b == 1) {
            return 1;
        } else if(b == 2) {
            return 0;
        } else if(b == 3) {
            return 2;
        } else if(b == 4) {
            return 1;
        }
    } else if(a == 3) {
        if(b == 0) {
            return 2;
        } else if(b == 1) {
            return 2;
        } else if(b == 2) {
            return 1;
        } else if(b == 3) {
            return 0;
        } else if(b == 4) {
            return 1;
        }
    } else if(a == 4) {
        if(b == 0) {
            return 1;
        } else if(b == 1) {
            return 1;
        } else if(b == 2) {
            return 2;
        } else if(b == 3) {
            return 2;
        } else if(b == 4) {
            return 0;
        }
    }
    return -1;
}
int main() {
    int n, na, nb;
    cin >> n >> na >> nb;
    vector<int>a(na), b(nb);
    int result_a = 0, result_b = 0;
    for(int i = 0;i < na;i++) {
        cin >> a[i];
    }
    for(int i = 0;i < nb;i++) {
        cin >> b[i];
    }
    for(int i = 0;i < n;i++) {
        int result = judge(a[i%na], b[i%nb]);
        if(result == 1) {
            result_a++;
        } else if(result == 2) {
            result_b++;
        }
    }
    cout << result_a << ' ' << result_b;
}