#include <iostream>
#include <string>

using namespace std;

int OxToNum(char ch){
    int result;
    if(ch >= '0' && ch <= '9')
        result = ch - '0';
    else{
        ch = tolower(ch);
        if(ch>='a' && ch<='f')
            result = ch - 'a' + 10;
    }
    return result;
}

int main(void){
    string input;
    while(getline(cin,input)){
        int result = 0;
        int size = input.size();
        for(int i=2; i<size; i++){
            result = result*16 + OxToNum(input[i]);
        }
        cout<<result<<endl;
    }
    return 0;
}