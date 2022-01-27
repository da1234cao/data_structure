#include <iostream>
#include <string>

using namespace std;

int main(void){
    string input;
    getline(cin,input);
    
    int size = input.size();
    int result = 0;
    for(int i=size-1; i>=0; i--){
        if(input[i] != ' ')
            result++;
        else
            break;
    }
    cout<<result;

    return 0;
}