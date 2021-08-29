#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2,-1);

        unordered_multimap<int,int> numMap; // 键值对为：<val,loc>
        for(int i=0; i<nums.size(); i++)
            numMap.insert({nums[i],i});

        unordered_multimap<int,int>::iterator it;
        for(it=numMap.begin(); it!=numMap.end(); it=numMap.begin()){ // 遍历查询和为target的键，返回它们的下标
            pair<int,int> num(it->first,it->second);
            numMap.erase(it); // 避免自身干扰
            auto other = numMap.find(target-num.first); // 题目已经限定每种输入只会对应一个答案
            if(other != numMap.end()){
                result[0] = num.second;
                result[1] = other->second;
            }
        }

        return result;
    }
};

