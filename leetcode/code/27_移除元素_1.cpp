#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0, right=nums.size()-1; 
        while(left<right){
            while((nums[left]!=val) && (left<right)) // 从前向后找第一个val位置
                left++;
            while((nums[right]==val) && (left<right)) // 从后向前找第一个非val位置
                right--;
            // if(left<right)
            //     swap(nums[left],nums[right]);
            swap(nums[left],nums[right]); // 只有最后一次，自己和自己(不影响)，避免每次检查
            left++;
            right--;
        }

        int i=nums.size()-1;
        for(; i>=0; i--)
            if(nums[i]!=val)
                return i+1; // 前面非val长度
        return 0;
    }
};


int main(void){
    vector<int> nums = {3,2,2,3}; int val = 3;
    Solution s;

    int len = s.removeElement(nums,val);
    cout<<len<<endl;
    
    for(int i=0; i<len; i++)
        cout<<nums[i]<<" ";

    return 0;
}