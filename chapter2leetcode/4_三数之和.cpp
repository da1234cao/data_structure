#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 暴力解法：把三个轮着算一遍
// 这个方法有缺陷，不仅复杂度高，而且有重复的问题（因为没有顺序）
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {

//         sort(nums.begin(),nums.end());

//         vector<vector<int>> result;
//         // vector<int> tmp;

//         if(nums.size() < 3)
//             return result;

//         for(int i = 0; i < nums.size()-2; i++){
//             for(int j = i+1; j < nums.size()-1; j++){
//                 for(int k = j+1; k < nums.size(); k++){
//                     if(nums[i]+nums[j]+nums[k] == 0){
//                         vector<int> tmp = {nums[i],nums[j],nums[k]};
//                         result.push_back(tmp);
//                     } // 到这里，i对应的元素枚举过一遍
//                     while(k+1 < nums.size() && nums[k] == nums[k+1] ){//避免重复，下一个枚举不能是同一个元素
//                         k++;
//                     }
//                 }
//                 while(j+1 < nums.size()-1 && nums[j] == nums[j+1]){//避免重复，下一个枚举不能是同一个元素
//                         j++;
//                 }
//             }
//             while(i+1 < nums.size()-2 && nums[i] == nums[i+1]){//避免重复，下一个枚举不能是同一个元素
//                         i++;
//                 }
//         }

//         return result;
//     }
// };


// 双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // 排序预处理
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= 0){
                vector<vector<int>> part_result = twoSum(nums,i+1,nums.size()-1,-nums[i],nums[i]);
                if(!part_result.empty())
                    result.insert(result.end(),part_result.begin(),part_result.end());
                //再次选择元素进行枚举的时候，别选相同的数
                while (i+1 < nums.size() && nums[i] == nums[i+1]){
                    i++;
                }
            }else{
                break;
            }
        }
        
        return result;
    }

private:
    vector<vector<int>> twoSum(vector<int>& nums,int start,int end,int target,int value){
        vector<vector<int>> part_result;
        while (start < end){
            if(nums[start]+nums[end] == target){
                vector<int> one_result = {nums[start],nums[end],value};
                part_result.push_back(one_result);
                while (start + 1 < end && nums[start] == nums[start+1]){
                    start++;
                }
                start++;
                while(start < end -1 && nums[end] == nums[end-1]){
                    end--;
                } 
                end--;
            }else if(nums[start]+nums[end] < target){
                start++;
            }else{
                end--;
            }   
        }
        return part_result;
    }
};


int main(void){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // vector<int> nums = {};

    Solution s;

    vector<vector<int>> result = s.threeSum(nums);

    for(vector<vector<int>>::iterator it = result.begin(); it != result.end(); it++){
        for(int i = 0; i < (*it).size(); i++){
            cout<<(*it)[i]<<" ";
        }
        cout<<endl;
    }
}