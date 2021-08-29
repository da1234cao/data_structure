#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2,-1);

        unordered_map<int,int> numMap; // 键值对为<val,loc>
        for(int i=0; i<nums.size(); i++){
            if(numMap.count(target-nums[i])){
                result[0] = numMap[target-nums[i]];
                result[1] = i;
                break;
            }else{
                numMap.insert({nums[i],i});
            }
        }

        return result;
    }
};

