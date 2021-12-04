#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void heapify(vector<int>& nums, int n, int i){ 
        // 在nums[0,n]范围，对第i个元素，使用该函数。
        // 保证以第i个元素为根的堆，在调整的时候，不改变原来的结构
        int maxloc = i;
        int lc = 2*i + 1;
        int rc = 2*i + 2;
        if(lc<=n && nums[lc]>nums[maxloc])
            maxloc = lc;
        if(rc<=n && nums[rc]>nums[maxloc])
            maxloc = rc;
        if(i != maxloc){
            swap(nums[i],nums[maxloc]);
            heapify(nums, n, maxloc);
        }
    }

    void buildMaxHeap(vector<int>& nums){
        // 从最后一个父节点，倒着使用heapify
        // 倒着操作的原因：如果下面已经为堆。heapify不改变下面结构
        int n = nums.size()-1;
        int end = (n-1)/2;
        for(int i=end; i>=0; i--){
            heapify(nums,n,i);
        }
    }

    void heapSort(vector<int>& nums){
        // 先构建一个大顶堆。之后，每次将堆顶和最后一个元素交换
        buildMaxHeap(nums);
        int end = nums.size()-1;
        while(end>=0){
            swap(nums[0],nums[end]);
            end--;
            if(end >= 0)
                heapify(nums,end,0);
        }
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
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