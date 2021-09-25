#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    int sum=0;
    void backTracking(vector<int>& candidates, int target, int startIndex){
        // 递归出口
        if(sum == target){
            result.push_back(path);
            return;
        }
        
        for(int i=startIndex; i<candidates.size() && sum+candidates[i]<=target; i++){
            sum+=candidates[i];
            path.push_back(candidates[i]);
            // 排序保证：子节点的值要大于等于父节点。以剪枝
            // startIndex的迭代从本身节点开始(因为可以重复)。也意味着，之前选过的数不能再选。
            backTracking(candidates,target,i); 
            sum-=candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty())
            return {{}};
        sort(candidates.begin(),candidates.end());
        backTracking(candidates,target,0);
        return result;
    }
};