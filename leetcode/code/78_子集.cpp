#include <vector>

using namespace std;


class Solution {
private:
    vector<int> path;
    void backTracking(const vector<int>& nums, vector<vector<int>>& part_result, int n, int startIndex){
        // 从nums数字startIndex开始的位置，选择n个元素。结果保存在part_result
        // 递归出口
        if(path.size() == n){
            part_result.push_back(path);
            return;
        }

        for(int i=startIndex; path.size()+(nums.size()-i)>=n; i++){
            path.push_back(nums[i]);
            backTracking(nums,part_result,n,i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        for(int i=0; i<=nums.size(); i++){ // 从nums中选择0,1...nums.size个元素
            vector<vector<int>> part_result;
            backTracking(nums,part_result,i,0);
            for(auto path:part_result)
                result.push_back(path);
        }
        return result;
    }
};