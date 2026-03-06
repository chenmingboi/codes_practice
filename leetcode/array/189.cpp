#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //空间复杂度不做要求的情况下
    // void rotate(vector<int>&nums, int k) {
    //     int len = nums.size();
    //     vector<int>copy = nums;
    //     for(int i = 0;i < len;i++){
    //         int index = (i + k) % len;
    //         nums[index] = copy[i];
    //     }
    // }
    //空间复杂度要求为O(1)的情况下
    /*
    三次翻转
    nums = "----->-->"; k =3
    result = "-->----->";

    reverse "----->-->" we can get "<--<-----"
    reverse "<--" we can get "--><-----"
    reverse "<-----" we can get "-->----->"
    */
    void reverse(vector<int>&nums, int l, int r) {
        while(l <= r) {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            r--;
            l++;
        }
    }
    void rotate(vector<int>&nums, int k) {
        int len = nums.size();
        reverse(nums, 0, len-1);
        reverse(nums, 0, k % len - 1);
        reverse(nums, k % len, len-1);
    }
};

int main() 
{
    int n=0, k=0;
    cin >> n >> k;
    vector<int>nums(n);
    for(int i = 0; i < n;i++) {
        cin >> nums[i];
    }
    Solution sol;
    sol.rotate(nums, k);
    for(int i = 0;i < n;i++) {
        cout << nums[i] << ' ';
    }
}