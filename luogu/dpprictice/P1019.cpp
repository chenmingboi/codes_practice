#include<bits/stdc++.h>
using namespace std;

vector<string>word;
int ans = 0;
int n;

//这题有毛病，题目中没有说两个单词相连的时候是按照最小重合长度进行连接的
//比如hatat 和 atath相连 按理来说应该是hatath，但是题目要求的意思是hatatath只对一个at进行消除
string getdiff(const string& dragon, const string& w) {
    int len1 = dragon.length(), len2 = w.length();
    int samelen = 0;
    for(int k = 1;k <= min(len1, len1);k++) {
        bool flag = true;
        for(int i = 0;i < k;i++) {
            if(dragon[len1-k+i] != w[i]){
                flag = false;
                break;
            }
        }
        if(flag) {
            samelen = k;
            break;
        }
    }
    string ans;
    if(samelen != 0 && samelen != len1 && samelen != len2) {
        ans = w.substr(samelen);
    } else if(len1 == 0) {
        ans = w;
    }
    return ans;
}
void dfs(string& dragon, vector<int>& cnt, string diff) {
    dragon += diff;
    ans = max(ans, (int)dragon.size());
    for(int i = 0;i < n;i++) {
        if(cnt[i] < 2) {
            string add_str = getdiff(dragon, word[i]);
            if(add_str.size() != 0) {
                cnt[i]++;
                dfs(dragon, cnt, add_str);
                cnt[i]--;
                for(int j = 0;j < add_str.length();j++) dragon.pop_back();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    word.resize(n);
    for(int i = 0;i < n;i++) cin >> word[i];
    char dragon_head;
    cin >> dragon_head;
    for(int i = 0;i < n;i++) {
        if(word[i][0] == dragon_head) {
            vector<int>cnt(n, 0);
            string dragon;
            cnt[i]=1;
            dfs(dragon, cnt, word[i]);
        }
    }
    cout << ans;
    return 0;
}