/*
随便输入：
当输入不合法的时候：assert中断.(当然，还能改进成try)
输入合法的时候：正确输出。
+  #define elemType double   //不会模板，暂时这么用着，可以改变计算器的精度。
+  允许计算式中间出现空格（table是不行的）

*/

#ifndef _3_4_H_
#define _3_4_H_

#include<iostream>
#include<vector>
#include<stack>
#include<cctype>
#include<assert.h>
#include<cmath>
#define elemType double   //不会模板，暂时这么用着

using std::vector;using std::stack;
using std::cin;using std::cout;using std::endl;


class Calculator
{
private:
    vector<vector<char>> proprity_table= 
		{          
		    //   +   -   *   /    (   )   
			{'>','>','<','<','<','>','>'},
			{'>','>','<','<','<','>','>'},
			{'>','>','>','>','<','>','>'},
			{'>','>','>','>','<','>','>'},
			{'<','<','<','<','<','=','0'},
			{'>','>','>','>','0','>','>'},
			{'<','<','<','<','<','0','='} 	
		};//0就是 个数，默认表达式的输入不会出现语法错误 
    stack<elemType> OPND; //操作数栈
	stack<char> OPTR;  //运算符栈 
	int switch_optr(char a);    //符号对应的行/列位置
    char proprity_choice(char s_top_optr,char cur_optr);//符号优先级比较
	elemType operate(elemType opnd1,char optr,elemType opnd2);
public:
	elemType calculate(void);          //计算
	void loop_calculate(void);
};

int Calculator::switch_optr(char a)
{
	int temp=0;
	switch(a)
	{
		case '+':temp=0;break;
		case '-':temp=1;break;
		case '*':temp=2;break;
		case '/':temp=3;break;
		case '(':temp=4;break;
		case ')':temp=5;break;
		case '#':temp=6;break;
		default: cout<<"switch_optr fault---> enter the illegal symbol";
			exit(EXIT_FAILURE);
	}
	return temp;
}

char Calculator::proprity_choice(char s_top_optr,char cur_optr)
{
	int i,j;
	i=switch_optr(s_top_optr);
	j=switch_optr(cur_optr);
	if(proprity_table[i][j]=='0')
	{
		cout<<"enter optr error"<<endl;
		exit(EXIT_FAILURE);
	}
	return proprity_table[i][j];
}

elemType Calculator::operate(elemType opnd1,char optr,elemType opnd2)
{
	elemType ans;
	switch (optr)
	{
	case '+':ans=opnd1+opnd2;
		break;
	case '-':ans=opnd1-opnd2;
		break;
	case '*':ans=opnd1*opnd2;
		break;
	case '/':ans=opnd1/opnd2;
		break;
	}
	return ans;
}

elemType Calculator::calculate(void)
{
	OPTR.push('#');
	char ch;
	ch=getchar();
	while(ch!='#' || OPTR.top()!='#')
	{
		if(isdigit(ch))  //读取数字部分
		{
			int integer_num=0;
			integer_num=integer_num*10+ch-'0';
			ch=getchar();
			while(isdigit(ch))
			{
				integer_num=integer_num*10+ch-'0';
				ch=getchar();
			}
			double decimal_num=0;
			if(ch=='.')
			{
				// double decimal_num=0;
				int cnt=1;
				ch=getchar();
				while (isdigit(ch))
				{
					decimal_num=decimal_num+(ch-'0')*(pow(0.1,cnt));
					cnt++;
					ch=getchar();
				}	
			}
			elemType num = integer_num + decimal_num;
			OPND.push(num);
		}
		else
		{
			char proprity=proprity_choice(OPTR.top(),ch);
			switch (proprity)
			{
			case '<':OPTR.push(ch);ch=getchar();
				break;
			case '=':OPTR.pop();ch=getchar();
				break;
			case '>':
				elemType opnd2=OPND.top();OPND.pop();
				elemType opnd1=OPND.top();OPND.pop();
				char optr=OPTR.top();OPTR.pop();
				elemType ans=operate(opnd1,optr,opnd2);
				OPND.push(ans);
				break;
			}
		}
		while(ch==' ')
		{
			ch=getchar();// 排除空格的干扰
		}
		if(ch=='\n')
			ch='#';//输入结束标志		
	}
	return OPND.top();
}

void Calculator::loop_calculate(void)
{
	while (1)
	{
		elemType ans=calculate();
		cout<<ans<<endl;
	}
}

#endif 