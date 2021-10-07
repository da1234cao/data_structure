#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> vault{{5,0},{10,0},{20,0}}; //<面额，数量>

        for(int i=0; i<bills.size(); i++){
            switch (bills[i]){
            case 5:
                vault[5]++;
                break;
            case 10:
                vault[10]++;
                if(vault[5]>=1)
                    vault[5]--;
                else
                    return false;
                break;
            case 20:
                vault[20]++;
                if(vault[10]>=1 && vault[5]>=1){
                    vault[10]--;
                    vault[5]--;
                }else if(vault[5]>=3)
                    vault[5] -= 3;
                else
                    return false;
            default:
                exit;
            }
        }

        return true;
    }
};