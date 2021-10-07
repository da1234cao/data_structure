#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // 统计拐点个数(包含两边端点)
        int result = 0;
        int preDiff = 0;
        int curDiff = 0;
        for(int i=0; i<nums.size()-1; i++){
            curDiff = nums[i+1] - nums[i];
            // if(preDiff & curDiff < 0){
            if((preDiff<=0 && curDiff>0) || (preDiff>=0 && curDiff<0)){
                result++;
                preDiff = curDiff;
            }
        }
        result++; // 最后一个默认是拐点
        return result;
    }

    void subscriptWiggleMaxLength(vector<int>& nums, vector<int>& subscript){
        int preDiff = 0;
        int curDiff = 0;
        for(int i=0; i<nums.size()-1; i++){
            curDiff = nums[i+1] - nums[i];
            if((preDiff<=0 && curDiff>0) || (preDiff>=0 && curDiff<0)){
                subscript.push_back(i);
                preDiff = curDiff;
            }
        }
        subscript.push_back(nums.size()-1);
    }
};

int main(void){
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    Solution s;
    int wiggle_max_length = s.wiggleMaxLength(nums);
    vector<int> subscript;
    s.subscriptWiggleMaxLength(nums,subscript);
    
    cout<<"wiggle max length:"<<wiggle_max_length<<endl;
    cout<<"wiggle max length element:";
    for(auto i : subscript){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}