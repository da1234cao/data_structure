#include <iostream>
#include <string>

using namespace std;

char otherPair(char alpha){
    if(alpha<='z' && alpha>='a')
        return (char)('A' + alpha - 'a');
    if(alpha<='Z' && alpha>='A')
        return (char)('a' + alpha - 'A');
    return ' ';// 不会执行到这一步
}

int main(void){
    string input;
    char alpht;

    getline(cin,input);
    cin>>alpht;

    char other_pair = otherPair(alpht);

    int size = input.size();
    int result = 0;
    for(int i=0; i<size; i++){
        if(input[i] == alpht || input[i] == other_pair)
            result++;
    }
    cout<<result;

    return 0;
}