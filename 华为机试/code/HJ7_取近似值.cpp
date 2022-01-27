#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    float n;
    cin>>n;

    int result = 0;
    int point_num = (int)(n*10)%10;
    if(point_num >= 5)
        result = (int)n + 1;
    else
        result = (int)n;
    
    cout<<result;

    return 0;
}