#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    void backTracking(vector<int>& nums, vector<int>& path, vector<vector<int>>& result, int startIndex){
        if(path.size()>=2){ // 记录回溯树中，记录长度大于等于2的连续树枝
            result.push_back(path);
        }
        
        set<int> level_appear; // 同一层中已经从出现的元素
        for(int i=startIndex; i<nums.size(); i++){
            if(level_appear.count(nums[i])                                  // 横向扩展上，同一层不要出现相同的节点
               || !path.empty() && i<nums.size() && nums[i]<path.back())    // 深度扩展上，选择的一个节点>=当前path最后一个节点
                continue;

            level_appear.insert(nums[i]);
            path.push_back(nums[i]);
            backTracking(nums,path,result,i+1);
            path.pop_back();
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> result;
        backTracking(nums,path,result,0);
        return result;
    }
};

int main(void){
    vector<int> nums = {1,2,3,1,2,3,1,2,3};
    Solution s;
    vector<vector<int>> result = s.findSubsequences(nums);
    for(auto one : result){
        for(auto num : one)
            cout<<num<<" ";
        cout<<endl;
    }
}