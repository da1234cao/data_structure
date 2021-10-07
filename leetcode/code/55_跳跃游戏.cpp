#include <vector>

using namespace std;

class Solution {
public:
    bool backTracking(vector<int>& nums, int start, int& pass){
        if(pass >= nums.size()-1)
            return true;
        
        for(int step=nums[start]; step>0; step--){
            pass += step; // 尝试向前走step
            if(backTracking(nums,start+step,pass)) return true; // 成功则层层true退出
            pass -= step; // 退回step
        }
        return false; // 当前位置，所有step尝试均为到达，返回false，进行回退
    }

    bool canJump(vector<int>& nums) {
        int start = 0;
        int pass = 0;
        return backTracking(nums,start,pass);
    }
};