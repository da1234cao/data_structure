#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void backTracking(const vector<int>& nums, const int& target, int& sum, int& cnt){
        if(sum==target){
            cnt++;
            return;
        }

        for(int i=0; i<nums.size() && sum+nums[i]<=target; i++){
            // 同一层不可以出现相同的元素；这个判断没必要，题目已经限定为不同元素
            if(i>0 && nums[i]==nums[i-1])
                continue;
            sum += nums[i];
            backTracking(nums,target,sum,cnt);
            sum -= nums[i];
        }
    }

    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int cnt = 0;
        int sum = 0;
        backTracking(nums,target,sum,cnt);
        return cnt;
    }
};

int main(void){
    vector<int> nums = {1,2,3};
    // int target = 4;
    int target = 32; //结果为181997601
    Solution s;
    cout<<s.combinationSum4(nums,target)<<endl;
}