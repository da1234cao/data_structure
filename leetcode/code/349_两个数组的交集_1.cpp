#include <set>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(),nums1.end());
        set<int> set2(nums2.begin(),nums2.end());

        vector<int> result;
        set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),back_inserter(result));

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