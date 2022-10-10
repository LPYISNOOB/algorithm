/*
问题描述：
国防部（DND）要用无线网络连接北部几个哨所。两种不同的通信技术被用于建立网络：
每一个哨所有一个无线电收发器，一些哨所将有一个卫星频道。
任何两个有卫星信道的哨所可以通过卫星进行通信，而不管他们的位置。
同时，当两个哨所之间的距离不超过D时可以通过无线电通讯，D取决于对收发器的功率。
功率越大，D也越大，但成本更高。出于采购和维修的方便，所有哨所的收发器必须是相同的；那就是说，D值对每一个哨所相同。
 
你的任务是确定收发器的D的最小值。每对哨所间至少要有一条通信线路（直接或间接）
输入的第一行是测试数据的数量N。
每组测试数据的第一行包含卫星频道的数量S（1 < = S < = 100）和哨所的数量P（S < P < = 500）。
接下来的P行，给出以公里为单位的每个哨所的坐标(x,y)( 坐标为0到10000之间的整数)。
对于每组测试数据，输出一行，输出收发器的D的最小值。精确到小数点后两位
*
求解思路：最小生成树（prim算法）+贪心 
（1）先把所有的数，每个点的坐标保存起来 ，fach函数用于求两个点之间的距离，
dis数组保存 Initial用于初始化，将距离保存在二维数组中，用于构建矩阵，建立最小生成树 
FindMin()函数用于找到最小的距离， Prim(int k)用prim构建最小生成树，从第k个数构建 
（2） 构建完最小生成树后，选取最大的边用卫星通信，卫星用完后生成树最大边，即最大距离就是D的值。 
*
提交状态：AC
*
AC结果：
220K	16MS
*
出错次数：
1、2次
错误结果：

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
