#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    void canAppear(const vector<vector<char>>& board, pair<int,int> loc, vector<char>& can_appr){
        // 给定数独，和某个位置。将位置目前可以填充的数字放入can_appr中

        set<char> appred; // 保存所在行，列，正方形内出现过的数字
        
        // 正方形内出现过的数字
        pair<int,int> upper_left_corner(loc.first/3*3,loc.second/3*3);
        for(int i=upper_left_corner.first; i<upper_left_corner.first+3; i++){
            for(int j=upper_left_corner.second; j<upper_left_corner.second+3; j++){
                if(board[i][j]!='.')
                    appred.insert(board[i][j]);
            }
        }

        // 所在行出现过的数字
        for(int i=0; i<board.size(); i++){
            if(board[loc.first][i]!='.')
                appred.insert(board[loc.first][i]);
        }

        // 所在列出现过的数字
        for(int i=0; i<board.size(); i++){
            if(board[i][loc.second]!='.')
                appred.insert(board[i][loc.second]);
        }

        // 将本位置，目前可以出现的数字，保存到can_appr中
        for(char num='1'; num<='9'; num++){
            if(appred.count(num))
                continue;
            else
                can_appr.push_back(num);
        }

    }


    pair<int,int> nextLoc(const vector<vector<char>>& board,pair<int,int> loc){
        // 当前位置的下一个位置
        if(loc.second<board.size()-1)
            return {loc.first, loc.second+1};
        else
            return {loc.first+1,0};
    }

    pair<int,int> nextPointLoc(const vector<vector<char>>& board,pair<int,int> loc){
        // 当前位置的下一个'.'位置。或者，是超出范围的最后一行的下一行开头位置
        pair<int,int> next_loc = nextLoc(board,loc);
        while(next_loc.first<board.size() && board[next_loc.first][next_loc.second] != '.'){
            next_loc = nextLoc(board,next_loc);
        }
        return next_loc;
    }


    bool backTracking(vector<vector<char>>& board,pair<int,int> loc){
        // 题目数据 保证 输入数独仅有一个解
        // 从上向下，从左到右，填充数独

        // 填充完毕，返回
        if(loc.first == board.size())
            return true;
        

        if(board[loc.first][loc.second] != '.') // 已经存在数字，跳转到需要填充的位置。回溯过程中，仅开头可能会使用一次
            loc = nextPointLoc(board,loc); 
                
        vector<char> can_appr;
        canAppear(board,loc,can_appr); // 统计目前当前位置可以出现的数字
        for(int k=0; k<can_appr.size(); k++){
            board[loc.first][loc.second] = can_appr[k]; // 尝试填入一个
            pair<int,int> next_loc = nextPointLoc(board,loc); // 计算下一个需要填充的位置

            // for(auto vec : board){
            //     for(auto ch : vec)
            //         cout<<ch<<" ";
            //     cout<<endl;
            // }
            // cout<<endl;

            if(backTracking(board,next_loc)) {
                return true; // 遇到一个可行解，true层层退出
            }
            else{
                board[loc.first][loc.second] = '.'; // 删除填入的内容

                // for(auto vec : board){
                //     for(auto ch : vec)
                //         cout<<ch<<" ";
                //     cout<<endl;
                // }
                cout<<endl;
            }
        }
  
        return false; // 当目前位置可以尝试的都尝试，也没有true出时，返回false
    }


    void solveSudoku(vector<vector<char>>& board) {
        backTracking(board,{0,0});
    }
};


int main(void){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    Solution s;
    s.solveSudoku(board);
    for(auto vec : board){
        for(auto ch : vec)
            cout<<ch<<" ";
        cout<<endl;
    }                            
}