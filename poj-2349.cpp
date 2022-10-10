/*
����������
��������DND��Ҫ�������������ӱ����������������ֲ�ͬ��ͨ�ż��������ڽ������磺
ÿһ��������һ�����ߵ��շ�����һЩ��������һ������Ƶ����
�κ������������ŵ�����������ͨ�����ǽ���ͨ�ţ����������ǵ�λ�á�
ͬʱ������������֮��ľ��벻����Dʱ����ͨ�����ߵ�ͨѶ��Dȡ���ڶ��շ����Ĺ��ʡ�
����Խ��DҲԽ�󣬵��ɱ����ߡ����ڲɹ���ά�޵ķ��㣬�����������շ�����������ͬ�ģ��Ǿ���˵��Dֵ��ÿһ��������ͬ��
 
���������ȷ���շ�����D����Сֵ��ÿ������������Ҫ��һ��ͨ����·��ֱ�ӻ��ӣ�
����ĵ�һ���ǲ������ݵ�����N��
ÿ��������ݵĵ�һ�а�������Ƶ��������S��1 < = S < = 100��������������P��S < P < = 500����
��������P�У������Թ���Ϊ��λ��ÿ������������(x,y)( ����Ϊ0��10000֮�������)��
����ÿ��������ݣ����һ�У�����շ�����D����Сֵ����ȷ��С�������λ
*
���˼·����С��������prim�㷨��+̰�� 
��1���Ȱ����е�����ÿ��������걣������ ��fach����������������֮��ľ��룬
dis���鱣�� Initial���ڳ�ʼ���������뱣���ڶ�ά�����У����ڹ������󣬽�����С������ 
FindMin()���������ҵ���С�ľ��룬 Prim(int k)��prim������С���������ӵ�k�������� 
��2�� ��������С��������ѡȡ���ı�������ͨ�ţ�������������������ߣ������������D��ֵ�� 
*
�ύ״̬��AC
*
AC�����
220K	16MS
*
���������
1��2��
��������

*/

#include <stdio.h>
#include <math.h>
#define To2(x) (x)*(x)
#define MAXN 501
typedef struct
{	int x;
	int y;
}Point;

Point vex[MAXN];
double G[MAXN][MAXN],dis[MAXN];
int vexnum,visited[MAXN];
int S,P;

double fach(int i,int j)
{	
	return	(double)sqrt((double)(To2(vex[i].x-vex[j].x)+To2(vex[i].y-vex[j].y)));
}

void Initial(int N)
{	int i,j;
	for(i = 1;i <= N;++i)
		for(j = 1;j <= i;++j)
			G[i][j] = G[j][i] = fach(i,j);
	vexnum = N;
}

int FindMin()
{	int i,k = -1;
	double min = 100000;
	for(i = 1;i <= vexnum;++i)
	{	if(visited[i] == 1)	continue;
		if(dis[i] < min)		k = i,min = dis[i];
	}
	return k;	
}

void qsort(int left,int right)
{	if(left < right)
	{	int i = left,j = right;
		double pivot = dis[left];
		while(i < j)
		{	while(i < j&&dis[j] >= pivot)	j--;
			if(i < j)		
				dis[i++] = dis[j];
			while(i < j&&dis[i] < pivot)	i++;
			if(i < j)		
				dis[j--] = dis[i];
		}
		dis[i] = pivot;
		qsort(left,i-1);
		qsort(i+1,right);
	}
}

void Prim(int k)
{	int i,j;
	for(i = 1;i <= vexnum;++i)
		dis[i] = G[k][i],visited[i] = 0;
	dis[k] = 0,visited[k] = 1;
	for(i = 1;i<vexnum;++i)
	{	k = FindMin();
		if(k == -1)	break;
		visited[k] = 1;
		for(j = 1;j <= vexnum;++j)
		{	if(visited[j] == 1)	continue;
			if(dis[j] > G[k][j])	dis[j] = G[k][j];	
		}
	}
	qsort(1,vexnum);
	printf("%.2lf\n",dis[vexnum-S+1]);
}

int main()
{	int N,i;
	scanf("%d",&N);
	while(N--)
	{	scanf("%d %d",&S,&P);
		for(i = 1;i <= P;++i)
			scanf("%d %d",&vex[i].x,&vex[i].y);
		Initial(P);
		Prim(1);
	}
	return 0;
}
