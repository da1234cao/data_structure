#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct cmp{
        bool operator() (vector<int>& v1, vector<int>& v2){
            // start越小，越靠前；start相同，end越小，越靠前
            if(v1[0]<v2[0])
                return true;
            else if(v1[0]==v2[0])
                return v1[1]<v2[1];
            else
                return false;
        }
    };

    int findMinArrowShots(vector<vector<int>>& points) {
        // 反例：[[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
        sort(points.begin(),points.end(),cmp());
        int count = 1; //   1 <= points.length <= 10^4
        int start = points[0][0];
        int end = points[0][1];
        for(int i=1; i<points.size(); i++){
            if(points[i][0]>=start && points[i][0]<=end){
                // 当前气球，可以被上一个气球连带zhapo
                // 同时缩小范围，范围为一针可以都扎破的范围
                start = min(start,points[i][0]);
                end = min(end,points[i][1]);
                continue; 
            }
            // 开启新的范围
            count++;
            start = points[i][0];
            end = points[i][1];
        }
        return count;
    }
};