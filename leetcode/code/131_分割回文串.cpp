#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;
public:
    bool is_palindrome(const string& s, int left, int right){
        // 判断闭区间s[left,right]是否为回文字符串
        bool flag = true;
        while(left <= right){
            if(s[left]!=s[right]){
                flag = false;
                break;
            }
            left++;
            right--;
        }
        return flag;
    }


    bool Palindrome_Partitioning(const string& s, vector<int>& cut_locs,vector<vector<string>>& result){
        // 传入切割位置cut_locs
        // 判断切割之后，是否均为回文串
        // 均为回文串，将结果放入result中，返回true；存在一个不为均为回文串，直接返回false；
        vector<string> palindrome;

        int left=0, right; // left=0,切在整个字符串最前面
        for(int i=0; i<=cut_locs.size(); i++){
            if(i == cut_locs.size()) // 切在字符串最后面
                right = s.size()-1;
            else
                right = cut_locs[i];
            if(!is_palindrome(s,left,right))
                return false;
            palindrome.push_back(string(s.begin()+left,s.begin()+right+1)); 
            left = right+1;
        }
        result.push_back(palindrome);
        return true;
    }

    void backTracking_cutlocs(const string& s, int cut_nums, vector<int>& cut, vector<vector<int>>& cuts, int startIndex=0){
        // 在字符串s中，切cut_nums次 == 从s.size()-1个位置中，选择cut_nums个
        // 将组合放入cuts
        if(cut_nums == 0) // 切0刀，直接返回
            return;
        if(cut.size() == cut_nums){
            cuts.push_back(cut);
            return;
        }
        for(int i=startIndex; i<=s.size()-1-1; i++){
            cut.push_back(i);
            backTracking_cutlocs(s,cut_nums,cut,cuts,i+1);
            cut.pop_back();
        }
    }


    vector<vector<string>> partition(string s) {
        for(int i=0; i<s.size(); i++){ // 不断添加切割次数
            vector<int> cut;
            vector<vector<int>> cuts;
            backTracking_cutlocs(s,i,cut,cuts); // 将切割i次的切割位置组合放入cuts中
            
            if(i==0)
                Palindrome_Partitioning(s,cut,result); // 没有切割，传入一个空数组
            else
                for(auto cut : cuts)
                    Palindrome_Partitioning(s,cut,result); // 传入切割位置。如果切割后全部子串为回文串，将该切割组合对应的全部子串，放入result中
            
        }
        return result;
    }
};

int main(void){

    // // 测试Palindrome_Partitioning函数
    // string s = "a";
    // vector<int> cut_locs = {};
    // vector<vector<string>> result;
    // Solution sol;
    // sol.Palindrome_Partitioning(s,cut_locs,result);
    // for(auto pal : result){
    //     for(auto str : pal)
    //         cout<<str<<" ";
    //     cout<<endl;
    // }

    string s = "a";
    Solution sol;
    vector<vector<string>> result = sol.partition(s);
    for(auto pal : result){
        for(auto str : pal)
            cout<<str<<" ";
        cout<<endl;
    }
}