#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    enum direct{ // 枚举方向，上下左右；all_direct用于记录方向个数
        right,down,left,up,all_direct
    };

public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n,0));
        int i = 0,j = -1; // i,j记录当前（已填充）位置
        int num = 1; // 填充数字初始值

        if(n==1){ // 长度为1的正方形单独处理
            result[0][0]=1;
            return result;
        }

        vector<int> circleStep = {n,n-1,n-1,n-2}; // 第一圈，上下左右四个方向的步长
        while(1){
        // 每一圈填充过程
        for(int k=0; k<all_direct; k++){ 
            if(k == right){ // 向右填充
                for(int s=0; s<circleStep[k]; s++){
                    j++; // 向右移动一格，为待填充空位
                    result[i][j] = num;
                    num++;
                }
                continue;
            }
            if(k == down){ // 向下填充
                for(int s=0; s<circleStep[k]; s++){
                    i++;
                    result[i][j] = num;
                    num++;
                }
                continue;
            }
            if(k == left){ // 向左填充
                for(int s=0; s<circleStep[k]; s++){
                    j--;
                    result[i][j] = num;
                    num++;
                }
                continue;
            }
            if(k == up){ // 向上填充
                for(int s=0; s<circleStep[k]; s++){
                    i--;
                    result[i][j] = num;
                    num++;
                }
                continue;
            }
        }

        for(auto &step : circleStep)
            step-=2;
        if(circleStep[right]<=0)
            break;
        }

        return result;
    }
};

int main(void){
    int n = 4;
    Solution s;
    vector<vector<int>> result = s.generateMatrix(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}