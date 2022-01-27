#include <iostream>
#include <string>

using namespace std;

int main(void){
    int input;
    cin>>input;

    string result;

    if(input == 0){
        result.push_back('0');
    }else{
        while(input>0){
            result.push_back(input%10 + '0');
            input /= 10;
        }
    }

    cout<<result;

    return 0;
}