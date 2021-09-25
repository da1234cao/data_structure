#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    int sum=0;
    void backTracing(vector<int>& candidates, int target, int startIndex){
        if(sum == target){
            result.push_back(path);
            return;
        }

        for(int i=startIndex; i<candidates.size() && sum+candidates[i]<=target; i++){
            path.push_back(candidates[i]);
            sum+=candidates[i];
            backTracing(candidates,target,i+1);
            path.pop_back();
            sum-=candidates[i];
            while(i+1<candidates.size() && candidates[i+1] == candidates[i]) // 水平层，跳过相同的选择
                i++; 
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backTracing(candidates,target,0);
        return result;
    }
};

int main(void){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    Solution s;
    vector<vector<int>> result = s.combinationSum2(candidates,target);
    for(auto path : result){
        for(auto num : path)
            cout<<num<<" ";
        cout<<endl;
    }
}