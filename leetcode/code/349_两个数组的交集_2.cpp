#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(),nums1.end());
        unordered_set<int> set2(nums2.begin(),nums2.end());

        vector<int> result;
        for(auto num : set1){
            if(set2.count(num))
                result.push_back(num);
        }

        return result;
    }
};

int main(void){
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};

    Solution s;
    
    vector<int> result = s.intersection(nums1,nums2);

    for(auto num : result)
        cout<<num<<" ";
}