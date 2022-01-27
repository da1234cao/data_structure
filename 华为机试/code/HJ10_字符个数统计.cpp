#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void){
    string input;
    getline(cin,input);

    set<char> count;

    for(int i=0; i<input.size(); i++){
        count.insert(input[i]);
    }

    cout<<count.size();

    return 0;
}