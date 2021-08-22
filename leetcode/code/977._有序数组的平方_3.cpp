#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 查询第一个大于等于0的位置
        vector<int>::iterator it = lower_bound(nums.begin(),nums.end(),0);
        int negative = distance(nums.begin(),it);
        
        // 合并两个有序表
        int len = nums.size();
        int i=negative-1,j=negative;
        vector<int> ans;
        while(i>=0 || j<len){
            if(i<0){
                ans.push_back(nums[j]*nums[j]);
                j++;
            }else if(j>=len){
                ans.push_back(nums[i]*nums[i]);
                i--;
            }else if(nums[i]*nums[i] < nums[j]*nums[j]){
                ans.push_back(nums[i]*nums[i]);
                i--;
            }else{
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        
        return ans;
    }
};

int main(void){
    vector<int> nums = {-7,-3,2,3,11};
    Solution s;
    vector<int> ans = s.sortedSquares(nums);
    for(auto tmp:ans)
        cout<<tmp<<" ";
}