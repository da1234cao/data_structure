#include <iostream>
#include <vector>
using namespace std;

bool isPrimerNum(int n){
    bool result = true;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            result = false;
            break;
        }
    }
    return result;
}


int main(void){
    int n;
    cin>>n;

    vector<int> result;
    for(int i=2; i<=n; i++){
        if(!isPrimerNum(i))
            continue;

        while(n%i == 0){
            n /= i;
            result.push_back(i);
        }

        if(n>=2 && isPrimerNum(n)){
            result.push_back(n);
            break;
        }
    }

    for(int i : result)
        cout<<i<<" ";
}