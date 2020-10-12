/**
 * 二进制数存储在数组中，长度相同；A[0]为高位
 * 相加的结果存储在另一个数组中。
*/
 
#include <iostream>
#include <vector>
 
using namespace std;
 
 
vector<int> add(const vector<int>& v1,const vector<int>& v2);
void printf_vector(const vector<int>& v);
 
int main(int argc, char const *argv[])
{
    vector<int> v1={0, 1, 1, 0, 0};
    vector<int> v2={1, 1, 0, 1, 0};
 
    vector<int> v3 = add(v1,v2);
    printf_vector(v3);
 
    return 0;
}
 
void printf_vector(const vector<int>& v){
    for(int i=0; i< v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
 
vector<int> add(const vector<int>& v1,const vector<int>& v2){
    if((v1.size() != v2.size()) && v1.size()!=0)
        return vector<int>();
    
    vector<int> v3(v1.size()+1);
 
    for(int i=v1.size()-1; i>=0; i--){
        //这里先考虑进位就好了
        v3[i] = (v1[i]+v2[i]+v3[i+1])/2; //进位
        v3[i+1] = (v1[i]+v2[i]+v3[i+1])%2;
    }
 
    return v3;
}
 