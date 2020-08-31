#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 快乐的暴力解法，求出两两之间的面积  --超时
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int maxArea = 0;
//         for(int i = 0; i < height.size()-1; i++){
//             for(int j = i+1; j < height.size(); j++){
//                 maxArea = max(maxArea, min(height[i],height[j])*(j-i));
//             }
//         }
//         return maxArea;
//     }
// };

/*使用双指针：使用左右指针指向边界，逐渐向中间靠拢。*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int l = 0, r = height.size()-1;
        while (l < r){
            maxArea = max(maxArea, min(height[l],height[r])*(r-l));
            height[l] < height[r] ? l++ : r--;
        }
        return maxArea;
    }
};

int main(void){
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    Solution s;
    int maxArea = s.maxArea(height); // 49

    cout<<maxArea<<endl;
}