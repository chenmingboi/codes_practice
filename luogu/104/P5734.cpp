#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    string s;
    cin >> s;
    for(int i = 0;i < q;i++){
        int op;
        cin >> op;
        if(op == 1) {
            string str;
            cin >> str;
            s += str;
            cout << s << endl;
        } else if (op == 2) {
            int a,b;
            cin >> a >> b;
            s = s.substr(a,b);
            cout << s << endl;
        } else if (op == 3) {
            int a;
            cin >> a;
            string str;
            cin >> str;
            s.insert(a, str);
            cout << s << endl;
        } else if (op == 4) {
            string str;
            cin >> str;
            int pos = s.find(str);
            if(pos != string::npos) {
                cout << pos << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}