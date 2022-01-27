#include <iostream>
#include <set>

using namespace std;

int main(void){
    int num;
    cin>>num;

    set<int> appear;
    int result = 0;
    while(num>0){
        int bit = num%10;
        num /= 10;
        if(appear.find(bit) != appear.end())
            continue;
        appear.insert(bit);
        result = result*10 + bit;
    }
    cout<<result;

    return 0;
}