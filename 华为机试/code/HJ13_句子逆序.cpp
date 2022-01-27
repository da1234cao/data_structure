#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

int main(void){
    string input;
    getline(cin,input);

    istringstream ss(input);
    string word;
    stack<string> data;
    while(ss>>word){
        data.push(word);
    }

    string result;
    while(!data.empty()){
        result += data.top();
        data.pop();
        result += ' ';
    }
    if(result.size()>0)
        result.pop_back();
    
    cout<<result;

    return 0;
}