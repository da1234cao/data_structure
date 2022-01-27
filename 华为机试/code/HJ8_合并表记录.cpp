#include <iostream>
#include <map>

using namespace std;

int main(void){
    int n;
    cin>>n;

    map<int,int> data;

    while(n>0){
        n--;
        int key,val;
        cin>>key;
        cin>>val;

        data[key] += val;
    }

    map<int,int>::iterator it;
    for(it=data.begin(); it!=data.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}