#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void){
    string input;
    while(getline(cin,input)){
        istringstream ss(input);
        string str_num;

        bool flag = true;
        int word_cnt = 0;

        while(getline(ss,str_num,'.')){
            // 格式检查
            if(str_num.empty() || !isdigit(str_num[0]) || (str_num[0]=='0' && str_num.size()>=2 && str_num[1]!='0')){
                flag = false;
                break;
            }
            // 数值范围检查
            int num = stoi(str_num);
            if(num>=0 && num<=255){
                word_cnt++;
                continue;
            }
            else{
                flag = false;
                break;
            }
        }

        if(flag == true && word_cnt == 4)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}