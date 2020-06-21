#include<iostream>
#include<vector>
#include<map>

using namespace std;

//方法一：暴力解
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         if(nums.size() < 2)
//             return vector<int> {NULL,NULL};
        
//         for(int i=0; i<nums.size()-1; i++){
//             for(int j=i+1; j<nums.size(); j++){
//                 if(nums[i]+nums[j] == target)
//                     return vector<int> {i,j};
//             }
//         }

//         return vector<int> {NULL,NULL};
//     }
// };

//方法二：使用map
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> result;
//         map<int, int> tmpmap;//键值为nums的值，变量值为nums下标
    
//         for (int i = 0; i < nums.size(); ++i) {
//             tmpmap[nums[i]] = i;
//         }
//         for (int i = 0; i < nums.size(); ++i) {
//             if (tmpmap.count(target - nums[i]) != 0 && tmpmap[target-nums[i]]!=i) {
//                 result.push_back(i);
//                 result.push_back(tmpmap[target - nums[i]]);
//                 break;
//             }
//         }
//         return result;
//     }
// };

//方法三：对方法二进行优化
//把缺少的部分，放入map中；当当前的内容和缺少的部分相等；它们的和即为target
class  Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> tmpmap;//键值为target-nums的值，变量值为nums下标
    
        for (int i = 0; i < nums.size(); ++i) {
            if (tmpmap.count(nums[i]) != 0) {
                result.push_back(tmpmap[nums[i]]);
                result.push_back(i);
                break;
            }
            tmpmap[target - nums[i]] = i;
        }
        return result;
    }
};


int main(void){
    vector<int> nums = {5, 2, 6, 11, 15, 7};
    int target = 9;

    Solution s;
    vector<int> tmp = s.twoSum(nums,target);

    cout<<"["<<tmp[0]<<","<<tmp[1]<<"]"<<endl;

    return 0;
}