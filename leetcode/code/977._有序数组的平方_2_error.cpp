#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 错误实现，反例：[-5,-3,-2,-1]
public:
    // vector<int> sortedSquares(vector<int>& nums) {
    //     //for_each(nums.begin(),nums.end(),abs); //这样写会报错，因为没有指定abs函数使用何种类型的重载
    //     // 折腾半天，也没搞定，你可以参考下面两个链接试试
    //     // https://stackoverflow.com/questions/12638166/g-compiler-error-couldnt-deduce-template-parameter-funct
    //     // https://stackoverflow.com/questions/14270475/for-each-and-transform
    //     for_each(nums.begin(),nums.end(),[](int& a) {a= a<0 ? -a:a;}); // 预处理数据，对每个元素取绝对值
        
    //     int left=0,right=nums.size()-1;
    //     while(left <= right){
    //         if(nums[left] <= nums[right]){
    //             nums[right]*=nums[right];
    //             right--;
    //         }else{
    //             swap(nums[left],nums[right]);
    //             nums[right]*=nums[right];
    //             right--;
    //         }
    //     }
    //     return nums;
    // }

    // 上面代码结构优化下
    vector<int> sortedSquares(vector<int>& nums) {
        for_each(nums.begin(),nums.end(),[](int& a) {a= a<0 ? -a:a;}); // 预处理数据，对每个元素取绝对值
        
        int left=0,right=nums.size()-1;
        while(left <= right){
            if(nums[left] > nums[right])
                swap(nums[left],nums[right]);
            nums[right]*=nums[right];
            right--;
        }
        return nums;
    }
};

int main(void){
    vector<int> nums = {-5,-3,-2,-1};
    Solution s;
    s.sortedSquares(nums);
    for(auto tmp:nums)
        cout<<tmp<<" ";
}