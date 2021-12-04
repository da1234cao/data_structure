#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void selectionSort(vector<int>& nums){
        for(int i=nums.size()-1; i>0; i--){ //nums(i,nums.size()-1]范围的元素已经排序
            int maxloc=0;
            for(int j=1; j<=i; j++){
                if(nums[j] > nums[maxloc])
                    maxloc = j;
            }
            if(i != maxloc)
                swap(nums[i],nums[maxloc]);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        selectionSort(nums);
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