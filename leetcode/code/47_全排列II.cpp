#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    void backTracking(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& result){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        set<int> level_prev; // 同一层，不可以出现重复
        for(int i=0; i<nums.size(); i++){
            if(used[i] || level_prev.count(nums[i])) // 纵向上，选择新节点时，使用过的不可再选；横向上，同一层不可有相同的元素
                continue;
            used[i] = true;
            level_prev.insert(nums[i]);
            path.push_back(nums[i]);
            backTracking(nums,used,path,result);
            path.pop_back();
            used[i] = false;
        }
        
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        vector<int> path;
        vector<vector<int>> result;
        backTracking(nums,used,path,result);
        return result;
    }
};


int main(void){
    vector<int> nums = {1,2,1};
    Solution s;
    vector<vector<int>> result = s.permuteUnique(nums);
    for(auto one : result){
        for(auto num : one)
            cout<<num<<" ";
        cout<<endl;
    }
}