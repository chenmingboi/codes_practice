#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int lp = 0, rp = 0;
        int len1 = word1.length(), len2 = word2.length();
        string result = "";
        while(lp < len1 || rp < len2) {
            if(lp < len1) {
                result.push_back(word1[lp]);
//                lp++;
                ++lp; //这里推荐用前置++
            }
            if(rp < len2) {
                result.push_back(word2[rp]);
                ++rp;
            }
        }
        return result;
    }
};

int main()
{
    string word1, word2, result;
    cin >> word1;
    cin >> word2;
    Solution sol;
    result = sol.mergeAlternately(word1, word2);
    cout << result << endl;
    return 0;
}