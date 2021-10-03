#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <set>

using namespace std;

class Solution {
private:
    vector<string> chessboard;
    vector<vector<string>> result;
     // 二维表示棋盘；棋盘中每个格子为一个集合，里面放入哪个Q占用
    vector<vector<set<pair<int,int>>>> used;

public:
    bool Q_used(pair<int,int> loc, int cmd){
        // flag = 0, 放置一个Q，所占用其所在行，列，对角线
        // flag = 1, 拿走一个Q，所释放其所在行，列，对角线
        // flag = 2, 检查该位置，能否放置Q。true表示可以放置，false表示不可放置
        const int n = used.size();
        const int row = loc.first;
        const int col = loc.second;

        if(cmd == 0){
            for(int i=0; i<n; i++) // 所在行累计标记flag
                used[row][i].insert({row,col});

            for(int i=0; i<n; i++) // 所在列累计标记flag
                used[i][col].insert({row,col});
            
            for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) // 左上方对角线，累计标记flag
                used[i][j].insert({row,col});
            for(int i=row+1, j=col+1; i<n && j<n; i++, j++) // 右下方对角线，累计标记flag
                used[i][j].insert({row,col});
            for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) // 右上方对角线，累计标记flag
                used[i][j].insert({row,col});
            for(int i=row+1, j=col-1; i<n && j>=0; i++, j--) // 右上方对角线，累计标记flag
                used[i][j].insert({row,col});
            return true;
        }else if(cmd == 1){
            for(int i=0; i<n; i++) 
                used[row][i].erase({row,col});

            for(int i=0; i<n; i++)
                used[i][col].erase({row,col});
            
            for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) 
                used[i][j].erase({row,col});
            for(int i=row+1, j=col+1; i<n && j<n; i++, j++) 
                used[i][j].erase({row,col});
            for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++)
                used[i][j].erase({row,col});
            for(int i=row+1, j=col-1; i<n && j>=0; i++, j--)
                used[i][j].erase({row,col});
            return true;
        }else if(cmd == 2){
            if(used[row][col].empty())
                return true;
            else
                return false;
        }else{
            cout<<"no such cmd"<<endl;
            exit(0);
        }
    }

    void backTracking(int start_row){
        // 出口之一： 当n*n的棋盘，成功放入n个Q
        if(start_row == used.size()){
            result.push_back(chessboard);
            return;
        }

        for(int i=0; i<used.size(); i++){
            if(Q_used({start_row,i},2) == false) // 检查{start_row,i}位置能否放入Q
                continue;
            Q_used({start_row,i},0); // 在{start_row,i}位置放入Q
            chessboard[start_row][i] = 'Q';
            backTracking(start_row+1); // 在下一行找合适的位置放置Q
            chessboard[start_row][i] = '.';
            Q_used({start_row,i},1); // 在{start_row,i}位置拿走Q
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        chessboard.resize(n,string(n,'.'));
        used.resize(n,vector<set<pair<int,int>>>(n,set<pair<int,int>>{}));
        backTracking(0);
        return result;
    }

};


int main(void){
    int n = 4;
    Solution s;
    vector<vector<string>> result = s.solveNQueens(6);
    for(auto one : result){
        for(auto str : one)
            cout<<str<<" ";
        cout<<endl;
    }
}