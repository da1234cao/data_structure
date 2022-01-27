#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    vector<vector<int>> datas;

    int cnt;
    while(cin>>cnt){
        vector<int> tmp(cnt,0);
        for(int i=0; i<cnt; i++)
            cin>>tmp[i];
        datas.push_back(tmp);
    }

    for(auto &tmp : datas)
        sort(tmp.begin(),tmp.end());
    
    // 去重+排序可以使用set
    for(auto &data : datas){
        cout<<data[0]<<endl;
        for(int i=1; i<data.size(); i++){
            if(data[i] == data[i-1])
                continue;
            cout<<data[i]<<endl;
        }
    }
}