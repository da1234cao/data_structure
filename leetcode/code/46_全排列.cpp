#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void backTracking(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& result){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(used[i])
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            backTracking(nums,used,path,result);
            path.pop_back();
            used[i] = false;
        }
        
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        vector<int> path;
        vector<vector<int>> result;
        backTracking(nums,used,path,result);
        return result;
    }
};


int main(void){
    vector<int> nums = {1,2,3};
    Solution s;
    vector<vector<int>> result = s.permute(nums);
    for(auto one : result){
        for(auto num : one)
            cout<<num<<" ";
        cout<<endl;
    }
}