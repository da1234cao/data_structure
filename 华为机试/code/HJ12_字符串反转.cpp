#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    string input;
    getline(cin,input);
    reverse(input.begin(),input.end());
    cout<<input;
    return 0;
}