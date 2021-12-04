#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void shellSort(vector<int>& nums){
        const int n = nums.size();
        for(int gap=n/2; gap>0; gap/=2){ //步长每次减半
            for(int i=0; i<gap; i++){ // 按照步长进行分组。每组进行插入排序
                for(int j=i+gap; j<n; j+=gap){
                    int val = nums[j];
                    int k = j-gap;
                    while(k>=0 && val<nums[k]){
                        nums[k+gap] = nums[k];
                        k-=gap;
                    }
                    nums[k+gap] = val;
                }
            }
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        shellSort(nums);
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