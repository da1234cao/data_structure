/*这是我当年写的程序（太长了，结构还行，不想重写一遍）
https://blog.csdn.net/sinat_38816924/article/details/79235640
当时寒假，在机器人团队，似乎还有些回忆
 */

#include<stdio.h>
#include<stdlib.h>
#define length 10
#define width 10
#define start_hang 1 //从0行开始计算row
#define start_lie 1//从0列开始column
#define end_hang 8
#define end_lie 8
#define STACK_INIT_SIZE	length*width 
char maze[width][length];
typedef struct
{
	int r;
	int c;
}postype;
typedef struct
{
	int ord;//通道块在路径上的序号
	postype seat;//通道块在迷宫中的坐标
	int di;//从此通道块走向下一通道块的方向 
}selemtype; 
typedef struct
{
	selemtype *base;
	selemtype *top;
	int stacksize;
}sqstack;
 
void initstack(sqstack *s)
{
	s->base=(selemtype *)malloc(STACK_INIT_SIZE*sizeof(selemtype));
	if(!s->base)
	{
		printf("创建空间失败");
		exit(0); 
	}
	s->top=s->base;
	s->stacksize=STACK_INIT_SIZE;
}
 
void push(sqstack *s,selemtype e)
{
	if(s->top-s->base>s->stacksize)//本题中，这里可以不写，因为STACK_INIT_SIZE=length*width 
	{
		s->base=(selemtype *)realloc(s->base,(s->stacksize+2)*sizeof(selemtype));
		if(!s->base)                // 当空间不足时，增加两个空间 
		{
			printf("栈增加空间失败");
			exit(0); 
		}
		s->top=s->base+s->stacksize;
		s->stacksize+=2;
	}
	*s->top++=e;//printf("$**");//检验入栈 
}
 
 
void readmaze()//从文件中读入迷宫 。用#表示墙壁，用.表示通路，重点用B表示 
{
	char ch;
	int i,j;
	FILE *fp;
	fp=fopen("maze.txt","r");
	if(fp==NULL)
	{
		printf("打开迷宫文件失败");
		exit(0); 
	}
	for(i=0;i<width;i++)
	{
		for(j=0;j<length;j++)
		{
			ch=fgetc(fp);
			maze[i][j]=ch;
		}
		ch=fgetc(fp);//用来接收换行符 
	}
	for(i=0;i<width;i++)
	{
		for(j=0;j<length;j++)
		{
			printf("%c",maze[i][j]);
		}
		printf("\n");//输出换行 
	}
} 
 
int mazepath(sqstack *s,postype *start,postype *end)
{
	int footmark[length][width]={0};//走过但目前通的方块标记为1
	int i=0;
	selemtype e;
	postype curpos,endpos;
	curpos=*start;//printf("%d,%d",curpos.c,curpos.r);检查复制有无成功 
	endpos=*end;
	do
	{       //可以通行且没有走过的情况下进栈 
		if(maze[curpos.r][curpos.c]=='.'&&footmark[curpos.r][curpos.c]==0)
		{
			footmark[curpos.r][curpos.c]=1;
			i++;
			e.ord=i;
			e.seat=curpos;
			e.di=1;//初始化为1，默认将会向东走一步 
			push(s,e);
			if(curpos.r==endpos.r&&curpos.c==endpos.c)//求得路径存入栈中 
				return 1;     //若当前为出口位置，则结束 
			else
				curpos.c++;//否则切换到当前位置的东邻方块作为新的当前位置 
		}
		else
		{
			curpos=e.seat;//当前道路不通，回归上一个位置 
			if(e.di<4)//此时e虽然被复制进入栈中，但外面的e还没有改变 
			{				         //若栈不空，且栈顶位置尚有其他位置未经探索
				switch(e.di)         //每次都是对当前的位置curpos进行判断
	 								//下面的循环就要注意对curpos进行更新 
				{
					case 1:curpos.r++;e.di++;break;//向下 
					case 2:curpos.c--;e.di++;break;
					case 3:curpos.r--;e.di++;break;
					case 4:break;//四周不通 
				}
			}
			else if(e.di==4)//栈不空，但栈顶周围均不通
			{
				s->top--;//从路径中删除该通道块；//这里要补上标记 
				if(s->base!=s->top) //若栈不为空，重新测试新的栈顶 
				{
					e=*--s->top;//printf("@**");//验证出栈次数;
					s->top++;//s->top总是指向栈顶，最上面元素的上一层，这里将s->top归位 
					i--;//序号减一 
					curpos=e.seat;//对当前位置进行更新 
				} 
			}						  
		} 
	}while(s->base!=s->top); 
	return -1;//跳出循环说明没有路径
} 
 
void primazepath(sqstack *s)
{			//printf("$*******"); 
	selemtype e;
	while(s->base!=s->top)
	{
		e=*--s->top;
		printf("步数%d	位置%d,%d:\n",e.ord,e.seat.r,e.seat.c);
	}	
} 
 
int main(void)
{
	int m=2;
	sqstack s;
	initstack(&s); 
	readmaze();
	postype start,end;
	start.r=start_hang;
	start.c=start_lie;
	end.r=end_hang;
	end.c=end_lie;
	m=mazepath(&s,&start,&end);
	//printf("%d",m);
	if(m==-1)
	{
		printf("没有路径");
		exit(0); 
	} 
	primazepath(&s);

    return 0;
}