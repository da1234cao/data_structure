#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int size = nums.size();
        int result = -1;
        vector<int> count(size,0);
        for(int i=0; i<size; i++){
            count[nums[i]]++;
            if(count[nums[i]]>=2){
                result = nums[i];
                break;
            }
        }
        return result;
    }
};