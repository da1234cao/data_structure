#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        const int size = ratings.size();
        vector<int> left(size,0);
        vector<int> right(size,0);
        int result = 0;

        for(int i=0; i<size; i++){ // 从左向右，满足规则
            if(i>0 && ratings[i]>ratings[i-1])
                left[i] = left[i-1] + 1;
            else
                left[i] = 1;
        }

        for(int i=size-1; i>=0; i--){ // 从右向左，满足规则
            if(i<size-1 && ratings[i]>ratings[i+1])
                right[i] = right[i+1] + 1;
            else
                right[i] = 1;
        }

        for(int i=0; i<size; i++){
            result += max(left[i], right[i]); // 同时满足从左向右，从右向左规则
        }

        return result;
    }
};