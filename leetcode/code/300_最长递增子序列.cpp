#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void backTracking(const vector<int>& nums, int start, vector<int>& path, int& result){
        if(path.size() > result)
            result = path.size();
        
        for(int i=start; i<nums.size() && (path.size()+nums.size()-i)>result; i++){
            if(!path.empty() && nums[i]<=path.back())
                continue;
            path.push_back(nums[i]);
            backTracking(nums,i+1,path,result);
            path.pop_back();
        }
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> path;
        int result;
        backTracking(nums,0,path,result);
        return result;
    }
};

int main(void){
    vector<int> nums = {0,1,0,3,2,3};
    Solution s;
    cout<<s.lengthOfLIS(nums)<<endl;
}