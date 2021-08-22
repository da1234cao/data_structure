#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        vector<int> ans(nums.size(),0); 
        int ans_i = right;
        while(left<=right){
            if(nums[left]*nums[left] <= nums[right]*nums[right]){
                ans[ans_i--] = nums[right]*nums[right];
                right--;
            }
            else{
                ans[ans_i--] = nums[left]*nums[left];
                left++;
            }
        }
        return ans;
    }
};

int main(void){
    vector<int> nums = {-5,-3,-2,-1};
    Solution s;
    vector<int> ans = s.sortedSquares(nums);
    for(auto tmp:ans)
        cout<<tmp<<" ";
}