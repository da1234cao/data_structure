#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) // 如果自身是1，直接返回
            return true;
        
        vector<int> square_list(10,0); // 存储平方和(即数字的转换过程)
        for(int i=0; i<10; i++)
            square_list[i] = i*i;
        
        bool flag = true;
        int square_sum = 0;
        unordered_set<int> appeared; // 存储已经出现过的数字。如果循环计算过程中出现已经出现过的数字，则说明它不是快乐数字；陷入自我循环做无用功的中的人，应该是不快乐的
        for(n; n!=1; n=square_sum){
            square_sum = 0;
            if(appeared.count(n)){
                flag = false;
                break;
            }
            appeared.insert(n);

            while(n!=0){
                square_sum += square_list[n%10];
                n = n/10;
            }    
        }

        return flag;
    }
};