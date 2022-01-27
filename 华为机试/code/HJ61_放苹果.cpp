#include <iostream>
#include <vector>

using namespace std;

int result=0,high=0;
vector<vector<int>> paths;

void backTracking(int m, int n, int start,vector<int> &path){
    // 递归出口：当将m个苹果，放入不超过n个盘子时，退出
    if(m==0 && high<=n){
        result++;
        paths.push_back(path);
        return;
    }else if(m>0 && high>=n){
        return;
    }

    for(int i=start; i<=m; i++){
        // 将i个果子，放入一个新盘子

        // 要保证，第i个盘子里的果子>=第i-1个果子
        if(path.size()>=2 && i<path[path.size()-1])
            continue;

        m = m-i;
        high++;
        path.push_back(i);
        backTracking(m,n,i,path);
        m = m+i;
        high--;
        path.pop_back();
    }
}

int main(void){
    int m,n;
    while(cin>>m && cin>>n){
        result=0;
        high=0;
        int start=1;
        vector<int> path;
        backTracking(m,n,start,path);
        cout<<result<<endl;

        // for(auto path : paths){
        //     for(auto num : path)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
    }
}