#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        // 将n每位提取出来，放入num中; 注意，存入vector中的顺序是倒着的
        vector<int> num; 
        if(n==0)
            num.push_back(0);
        else{
            while(n>0){
                num.push_back(n%10);
                n = n/10;
            }
        }
        
        for(int i=0; i<num.size()-1; i++){ // 按照个位，十位，百位顺序比较
            if(num[i] >= num[i+1]) // 右边位等于等于左边位
                continue;
            else{
                int j=i;
                while(j>=0){
                    num[j]=9;
                    j--;
                }
                num[i+1]=num[i+1]-1;
            }
        }

        int result = 0;
        for(int i=0; i<num.size(); i++){
            result += num[i]*pow(10,i);
        }

        return result;
    }
};