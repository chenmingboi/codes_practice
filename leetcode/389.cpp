//
// Created by ironm on 25-11-8.
//

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26, 0);
        for(auto it : s) {
            cnt[it - 'a']++;
        }
        for(auto it : t) {
            cnt[it - 'a']--;
            if(cnt[it - 'a'] < 0) {
                return it;
            }
        }
        return ' ';
    }
};

int main() {
    Solution sol;

}