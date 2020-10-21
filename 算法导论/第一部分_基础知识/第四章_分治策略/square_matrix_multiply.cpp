/**
 * 平方矩阵乘法
 * 方法一：暴力法，时间复杂度O(n^3)
 * 方法二：Strassen算法略。
 * 参考视频：https://www.bilibili.com/video/BV16i4y147ck?from=search&seid=9028483803119787393
*/

#include <iostream>
#include <vector>

using namespace std;

bool check_square_matrix(const vector<vector<int>>& matrix);
void print_matrix(const vector<vector<int>>& matrix);
void square_matrix_multiply(const vector<vector<int>>& matrix_A, const vector<vector<int>>& matrix_B, vector<vector<int>>& matrix_C);

int main(void){
    vector<vector<int>> matrix_A = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> matrix_B = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> matrix_C;
    
    square_matrix_multiply(matrix_A,matrix_B,matrix_C);
    print_matrix(matrix_C);

    return 0;
}

void square_matrix_multiply(const vector<vector<int>>& matrix_A, const vector<vector<int>>& matrix_B, vector<vector<int>>& matrix_C){
    // 平方矩阵乘法,暴力法，很简答的

    //检查矩阵是否为平方矩阵
    if(!(check_square_matrix(matrix_A)&&check_square_matrix(matrix_B))){
        cout<<"input matrix is not square_matrix"<<endl;
        exit(0);
    }

    // 初始化结果矩阵C
    int n=matrix_A.size();
    matrix_C.resize(n);
    for(int i=0; i<n; i++){
        matrix_C[i].resize(n);
    }

    // i,j是用来标示C矩阵的位置。
    // 因而，i是A矩阵的行，j是B矩阵的列
    // 再加上一个增加的k，使得A元素按行遍历，B元素按列遍历
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix_C[i][j]=0;
            for(int k=0; k<n; k++){
                matrix_C[i][j]+=matrix_A[i][k]*matrix_B[k][j];
            }
        }
    }

}

bool check_square_matrix(const vector<vector<int>>& matrix){
    bool is_square_matrix=true;
    int row_len = matrix.size();
    for(int i=0; i< row_len; i++){
        if(matrix[i].size()!=row_len){
            is_square_matrix = false;
            break;
        }
    }
    return is_square_matrix;
}

void print_matrix(const vector<vector<int>>& matrix){
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}