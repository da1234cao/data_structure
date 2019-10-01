#include<stdio.h>
 
void hanoi(int n,char a,char b,char c)
{
	if(n==1)
		printf("%c-->%c\n",a,c);
	else
	{
		hanoi(n-1,a,c,b);//将a上的盘子通过c移动到b上，这句话很好 
		printf("%c-->%c\n",a,c);//可以仔细想想这c是什么柱子，挺好玩的 
		hanoi(n-1,b,a,c); 
	}
}
 
int main(void)
{
	hanoi(5,'x','y','z'); 
    return 0;
} 