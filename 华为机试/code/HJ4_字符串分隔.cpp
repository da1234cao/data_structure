#include <iostream>
#include <string>

using namespace std;

int main(void){
    string input;
    while(getline(cin,input)){
        int size = input.size()/8;
        int left = input.size()%8;

        for(int i=0; i<size; i++){
            for(int j=0; j<8; j++)
                cout<<input[i*8+j];
            cout<<endl;
        }

        if(left != 0){
            for(int i=0; i<left; i++){
                cout<<input[size*8+i];
            }
            for(int i=0; i<8-left; i++)
                cout<<'0';
            cout<<endl;
        }
    }

    return 0;
}