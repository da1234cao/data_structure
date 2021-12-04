#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void insertSort(vector<int>& nums){
        int n = nums.size();
        for(int i=1; i<n; i++){ //nums[0,i)范围有序，nums[i,nums.size()-1]范围内无序
            int j = i;
            int val = nums[j];
            while(j>0 && val<nums[j-1]){
                nums[j] = nums[j-1];
                j--;
            }
            if(j!=i)
                nums[j] = val;
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        insertSort(nums);
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