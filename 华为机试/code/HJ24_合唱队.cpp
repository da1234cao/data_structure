#include <vector>
#include <iostream>

using namespace std;

int main(void){
    int n;

    while(cin>>n){
        vector<int> students;
        vector<int> leftToRight(n,0);
        vector<int> rightToleft(n,0);

        while(n>0){
            n--;
            int tmp;
            cin>>tmp;
            students.push_back(tmp);
        }

        // 从左到右，统计小于当前元素的非连续递增子序列长度
        for(int i=1; i<students.size(); i++){
            for(int j=0; j<i; j++)
                if(students[i] > students[j])
                    leftToRight[i] = max(leftToRight[i], leftToRight[j]+1);
        }

        // 从右到左，统计小于当前元素的非连续递增子序列
        for(int i=students.size()-1-1; i>=0; i--){
            for(int j=students.size()-1; j>i; j--){
                if(students[i] > students[j])
                    rightToleft[i] = max(rightToleft[i],rightToleft[j]+1);
            }
        }

        int K=0;
        for(int i=0; i<students.size(); i++){
            K = max(K,leftToRight[i]+rightToleft[i]);
        }
        cout<<(students.size()-K-1)<<endl;
    }
    return 0;
}