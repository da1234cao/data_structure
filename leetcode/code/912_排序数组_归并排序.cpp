#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void merge(vector<int>& nums, int left, int mid, int right){
        // 将两个有序数组合并。这两个有序数组为[left,mid],[mid+1,right]
        vector<int> tmp(right-left+1);

        int i=left, j=mid+1, k=0;

        while(i<=mid && j<=right){
            if(nums[i]<=nums[j])
                tmp[k++] = nums[i++];
            else
                tmp[k++] = nums[j++];
        }

        while(i<=mid)
            tmp[k++] = nums[i++];
        
        while(j<=right)
            tmp[k++] = nums[j++];
        
        i=left;
        k=0;
        while(i<=right)
            nums[i++] = tmp[k++];
    }

    void recursiveMergeSort(vector<int>& nums, int left, int right){
        if(left>=right) // 递归出口
            return;
        int mid = left + (right-left)/2;
        recursiveMergeSort(nums, left, mid);
        recursiveMergeSort(nums, mid+1, right);
        merge(nums,left,mid,right);
    }

    void mergeSort(vector<int>& nums){
        recursiveMergeSort(nums,0,nums.size()-1);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums);
        return nums;
    }
};


int main(void){
    vector<int> nums = {5,1,1,2,0,0};
    Solution sol;
    vector<int> ans = sol.sortArray(nums);
    for(int num : ans)
        cout<<num<<" ";
}