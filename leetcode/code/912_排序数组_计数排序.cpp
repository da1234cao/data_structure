#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<int> countSort(const vector<int>& nums){
        if(nums.empty())
            return {};
        
        // 计算元素范围
        int minloc = 0;
        int maxloc = 0;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] < nums[minloc])
                minloc = i;
            if(nums[i] > nums[maxloc])
                maxloc = i;
        }
        int size = nums[maxloc]-nums[minloc]+1;
        vector<int> counts(size);

        for(int i=0; i<n; i++) // 统计元素出现次数
            counts[nums[i]-nums[minloc]]++;
        
        vector<int> ans;
        for(int i=0; i<size; i++){
            while(counts[i] != 0){
                ans.push_back(i+nums[minloc]);
                counts[i]--;
            }
        }

        return ans;
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        return countSort(nums);
    }
};


int main(void){
    // vector<int> nums = {5,1,1,2,0,0};
    vector<int> nums = {5,2,3,1};
    Solution sol;
    vector<int> ans = sol.sortArray(nums);
    for(int num : ans)
        cout<<num<<" ";
}