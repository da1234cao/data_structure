#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex=0,fastIndex=0;
        int len = nums.size();
        /// 没有要处理内容的时候，快慢指针一起向前走。
        /// 遇到需要处理内容的时候，慢指针留下标记，快指针继续向前走。
        /// 本题为例，使用[slowIndex,fastIndex)标记可以被填充的区域。[0,slowIndex)为非val列表
        for(; fastIndex<len; fastIndex++){
            if(nums[fastIndex]!=val){  
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
        }
        return slowIndex;
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