#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1 && nums[0]==0) // 只有一个元素，且该元素为0，不用前进，坐享其成
            return true;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0) // 不等于0，哪怕是走一步都可以前进
                continue;

            int j=i; 
            int val=0;
            while(j>=0){ // 遇到0，只要前面的数字不都掉入这个位置，也没关系
                if(nums[j] != val)
                    break;
                j--;
                val++;
            }
            if(j>=0 && nums[j]!=0 ) // 当前0，必须在遇见之前0之前，做出决断
                continue; // 0位置可以避过，继续前进
            else
                return false; // 0位置无法避过，必然入坑之后，无法动弹，返回false
        }
        return true;
    }
};

int main(void){
    vector<int> nums = {2,0,0};
    Solution s;
    cout<<s.canJump(nums);
}