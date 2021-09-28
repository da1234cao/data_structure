#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void backTracking(vector<int>& nums, int startIndex, vector<int>& path, vector<vector<int>>& result){
        result.push_back(path);
        for(int i=startIndex; i<nums.size(); i++){ // 层次展开
            path.push_back(nums[i]);
            backTracking(nums,i+1,path,result); // 深度展开
            path.pop_back();
            while(i+1<nums.size() && nums[i+1]==nums[i]) // 同一层次，与前面的数字相同，跳过
                i++;
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> path;
        vector<vector<int>> result;
        backTracking(nums,0,path,result);
        return result;
    }
};