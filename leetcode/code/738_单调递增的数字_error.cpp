#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    bool maxBehind(int cur, vector<int>& num){ // 在num中，cur位置的元素，是否大于等于cur之后的所有元素
        bool flag = true;
        for(int i=cur+1; i<num.size(); i++){
            if(num[cur]<num[i]){
                flag = false;
                break;
            }
        }
        return flag;
    }

    int monotoneIncreasingDigits(int n) {
        // 贪心思路：
        // 当前位置比后面所有位置都大；如果该位置不动，后面位置无论如何变化，都不可能调整成单调递增;所以将该位置后面的数字清零，再减一
        // 当前位置没有比后面所有位置都到，当前位置保留，后面自调整，使得单调递增。

        // 贪心思路，错误。反例：102
        // 错误原因，1虽然没有比后面的都大，但是后面不足以调整使得单调递增

        // 修正方法，必须保证紧邻1后面的那个数字大于1才行,这样后面才有修正能力。
        // 比如120。2大于1，有能力减一，保底保证2后面全为9

        // 修正方法，又有问题。比如1120。第一个1，无法跳过第二个1，得知后面有2来保证升序

        int result = 0;

        // 将n每位提取出来，放入num中
        vector<int> num; 
        if(n==0)
            num.push_back(0);
        else{
            while(n>0){
                num.push_back(n%10);
                n = n/10;
            }
        }
        reverse(num.begin(),num.end());

        for(int i=0; i<num.size(); i++){
            if(i==num.size()-1) // 最后一位不需要花里胡哨，直接保留
                result += num[i];
            else if(maxBehind(i,num)){ // cur位置的元素，大于等于cur之后的所有元素：直接将尾数置零，并减一
                result += (num[i]*pow(10,num.size()-i-1)-1);
                break;
            }else if(num[i+1]>num[i]){ // 保留当前元素不变
                result += num[i]*pow(10,num.size()-i-1);
            }
        }

        return result;
    }
};