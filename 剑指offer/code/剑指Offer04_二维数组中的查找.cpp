#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix.size()==0 || matrix[0].size()==0)
            return false;

        int row = matrix.size();
        int col = matrix[0].size();

        int i=0;
        int j=col-1;
        bool result=false;
        while(i<row && j>=0 && j<col){
            if(matrix[i][j] == target){
                result = true;
                break;
            }else if(matrix[i][j] > target){
                j--;
            }else{
                i++;
            }
        }

        return result;
    }
};