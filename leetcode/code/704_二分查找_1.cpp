#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1,mid;
        while(left <= right){
            // mid = (left+right)/2; /// 我看到官网是这个写法；想了下，应该是担心right+left的值超出了int的范围
            mid = left + (right - left)/2;
            
            if(target == nums[mid])
                return mid;
            else if(target > nums[mid])
                left = mid+1;
            else
                right = mid-1;
        }
        return -1;
    }
};

int main(void){
    vector<int> nums = {-1,0,3,5,9,12}; int target = 12;
    Solution s;
    int loc = s.search(nums,target);
    cout<<loc<<endl;
}