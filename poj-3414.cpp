/*
����������
���õ����������ֱ����A��B�������������ִ�����²�����

FILL��i�� ��ˮ��ͷ���� i ��1 �� i �� 2��;
DROP��i�� ���� i �������ˮ��;
POUR��i��j�� �ӹ� i ������ j;�ڴ˲���֮��Ҫô��j���������ҹ�i�п��ܻ�ʣ��һЩˮ����
Ҫô��i�ǿյģ����������������ﶼ��������j����
��дһ���������ҵ���Щ������������У���Щ������������һ�����в���ǡ��C����ˮ

*
���˼·������bfs�ķ�������� 
��1�� Init()����Ϊ��ʼ�������� BFS()Ϊ����������class State���ڱ�ʾˮ��״̬ 
 Next(int x,int y,State cur,int mode)Ϊ����·����״̬�ĺ����� PrintPath(int x,int y,int k)Ϊ��ӡ����ĺ��� 
��2�����ȶ�ȡABC,Ϊȫ�ֱ����� ����bfs���� 
��3��ÿ���������������D1/D2/F1/F2/P12/P21 P21��P12������ ��Ҫô��j���������ҹ�i�п��ܻ�ʣ��һЩˮ����Ҫô��i�ǿյģ����������������ﶼ��������j�� ��
ÿ����������Ѷ������浽v�����С� ����x��y��ֵ���£����档 
��4����ÿ�ֶ��������ֱ�ʾ ������ÿһ���Ķ������浽v�����У��Ա���������ÿ�ֶ��������� 

	   
*
�ύ״̬��AC
*
AC�����
284K	0MS
*
���������
3��4��
��������
�Ի����㷨���յĲ��ι̣���һЩC++�Դ�������ʶ��ȫ��������ʹ�÷����� 
�������ݵķ�Χ��׼ȷ��֪�������ݵķ�Χ������ֵ���ղ�׼


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
