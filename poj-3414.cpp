/*
问题描述：
你会得到两个锅，分别具有A和B升的体积。可以执行以下操作：

FILL（i） 从水龙头填充锅 i （1 ≤ i ≤ 2）;
DROP（i） 将锅 i 清空至下水道;
POUR（i，j） 从锅 i 倒到锅 j;在此操作之后，要么锅j已满（并且锅i中可能还剩下一些水），
要么锅i是空的（并且其所有内容物都已移至锅j）。
编写一个程序以找到这些操作的最短序列，这些操作将在其中一个罐中产生恰好C升的水

*
求解思路：仍用bfs的方法来求解 
（1） Init()函数为初始化函数、 BFS()为搜索函数、class State用于表示水的状态 
 Next(int x,int y,State cur,int mode)为保存路径和状态的函数、 PrintPath(int x,int y,int k)为打印步骤的函数 
（2）首先读取ABC,为全局变量、 进行bfs搜索 
（3）每次搜索有六种情况D1/D2/F1/F2/P12/P21 P21和P12有条件 、要么锅j已满（并且锅i中可能还剩下一些水），要么锅i是空的（并且其所有内容物都已移至锅j） ，
每次搜索都会把动作保存到v数组中、 并将x，y的值更新，保存。 
（4）将每种动作用数字表示 ，并把每一步的动作保存到v数组中，以便于最后输出每种动作的描述 

	   
*
提交状态：AC
*
AC结果：
284K	0MS
*
出错次数：
3、4次
错误结果：
对回溯算法掌握的不牢固，对一些C++自带函数认识不全，不懂得使用方法。 
测试数据的范围不准确认知，对数据的范围和特殊值把握不准


*/
#include <cstdio>
#include <cstring>
#include <queue>
#define N 111
#define S 99
#define D1 -1
#define D2 -2
#define F1 1
#define F2 2
#define P12 12
#define P21 21
using namespace std;

class Path
{
	public:
		int x;
		int y;
};

class State
{
	public:
		int x;
		int y;
		int k;

		State(){}
		State(int initx,int inity,int initk)
			:x(initx),y(inity),k(initk){}
};

int A,B,C;
int v[N][N];
Path path[N][N];
queue<State> q; 
void Init()
{
	memset(v,0,sizeof(v));
}

void Next(int x,int y,State cur,int mode)
{
	if(!v[x][y])
	{
		v[x][y] = mode;
		path[x][y].x = cur.x;
		path[x][y].y = cur.y;
		q.push(State(x,y,cur.k+1));
	}
}

State BFS()
{
	v[0][0] = S;
	path[0][0].x = -1;
	path[0][0].y = -1;
	q.push(State(0,0,0));
	State cur;
	while(q.size())
	{
		cur = q.front();
		q.pop();

		if(cur.x==C||cur.y==C)
		{
			while(q.size())
			{
				q.pop();
			}
			return cur;
		}

		Next(0,cur.y,cur,D1);
		Next(cur.x,0,cur,D2);
		Next(A,cur.y,cur,F1);
		Next(cur.x,B,cur,F2);
		int rx = A - cur.x;
		int ry = B - cur.y;
		if(cur.x<=ry)
		{
			Next(0,cur.y+cur.x,cur,P12);
		}
		else
		{
			Next(cur.x-ry,B,cur,P12);
		}
		if(cur.y<=rx)
		{
			Next(cur.x+cur.y,0,cur,P21);
		}
		else
		{
			Next(A,cur.y-rx,cur,P21);
		}
	}
	return State(-1,-1,-1);
}

void PrintPath(int x,int y,int k)
{
	if(!k)
	{
		return;
	}
	PrintPath(path[x][y].x,path[x][y].y,k-1);
	switch(v[x][y])
	{
		case D1:
			printf("DROP(1)\n");
			break;
		case D2:
			printf("DROP(2)\n");
			break;
		case F1:
			printf("FILL(1)\n");
			break;
		case F2:
			printf("FILL(2)\n");
			break;
		case P12:
			printf("POUR(1,2)\n");
			break;
		case P21:
			printf("POUR(2,1)\n");
			break;
	}
}

int main()
{
	Init();
	scanf("%d %d %d",&A,&B,&C);
	State ret = BFS();
	if(ret.k==-1)
	{
		printf("impossible\n");
	}
	else
	{
		printf("%d\n",ret.k);
		PrintPath(ret.x,ret.y,ret.k);
	}
}
