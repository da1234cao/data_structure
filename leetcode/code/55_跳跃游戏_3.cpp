#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = 0;
        int pass = start + nums[start];
        int max_pass = pass;

        if(max_pass>=nums.size()-1)
            return true;
        
        for(int i=start+1; i<=max_pass; i++){ 
            pass = i + nums[i];
            max_pass = max(max_pass,pass); // 不断前进，更新最远可到达位置
            if(max_pass >= nums.size()-1)
                return true;
        }

        return false;
    }
};

int main(void){
    vector<int> nums = {3,2,1,0,4};
    Solution s;
    cout<<s.canJump(nums);
}