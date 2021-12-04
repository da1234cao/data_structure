#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void bubbleSort(vector<int>& nums){
        for(int i=nums.size()-1; i>0; i--){ // 标记需要冒到的位置
            for(int j=0; j<i; j++){ // 每次从头冒泡
                if(nums[j] > nums[j+1])
                    swap(nums[j],nums[j+1]);
            }
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        bubbleSort(nums);
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