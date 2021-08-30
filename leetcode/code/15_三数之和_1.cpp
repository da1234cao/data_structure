#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int len = nums.size();
        vector<vector<int>> result;
        // unordered_set<vector<int>> resultSet; // unordered_set默认没有对vector的hash方法
        set<vector<int>> resultSet;

        if(len<3){ // 不足三个元素，直接返回
            return result;
        }
        
        unordered_multimap<int, pair<int,int>> twoNums; // 存储两数之和，键值对为<两数之和，<数1下标，数2下标>>
        for(int i=0; i<len; i++){
            for(int j=i+1; j<len; j++)
                twoNums.insert({nums[i]+nums[j],{i,j}});
        }

        for(int i=0; i<len; i++){  // 将和为零的下标三元组排序之后，放入set，以去重
            int needNum = -nums[i];
            auto n = twoNums.count(needNum);
            if(n==1){
                auto it = twoNums.find(needNum);
                if(i!=it->second.first && i!=it->second.second){ // 避免自身重复
                    vector<int> oneAnsLoc = {i,it->second.first,it->second.second};
                    sort(oneAnsLoc.begin(),oneAnsLoc.end());
                    resultSet.insert(oneAnsLoc);
                }
            }else if(n>1){
                auto pr = twoNums.equal_range(needNum);
                while(pr.first != pr.second){
                    if(i!=pr.first->second.first && i!=pr.first->second.second){
                        vector<int> oneAnsLoc = {i,pr.first->second.first,pr.first->second.second};
                        sort(oneAnsLoc.begin(),oneAnsLoc.end());
                        resultSet.insert(oneAnsLoc);
                    }
                    pr.first++;
                }
            }
        }

        // resultSet中存储的是下标不重复的组合，下面在进行元素不重复
        set<vector<int>> real_resultSet;
        for(auto oneAnsLoc : resultSet){ // 将set中的内容拷贝到vector中
            vector<int> oneAns;
            for(auto i : oneAnsLoc)
                oneAns.push_back(nums[i]);
            sort(oneAns.begin(),oneAns.end());
            real_resultSet.insert(oneAns);
        }

        // 将元素和为零的组合，复制到vector中
        for(auto oneAns : real_resultSet){
            result.push_back(oneAns);
        }
        return result;
    }
};

int main(void){
    vector<int> nums={1,1,-2};
    Solution s;
    s.threeSum(nums);
}