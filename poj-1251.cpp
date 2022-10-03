/*
问题描述：
热带拉格里尚岛的元老有一个问题。几年前，大量外国援助资金花在了村庄之间的额外道路上。
但丛林无情地超越了道路，因此大型道路网络维护成本太高。长老会议必须选择停止维护一些道路。
左上方的地图显示了目前使用的所有道路以及每月维护这些道路的成本（以 aacms 为单位）。
当然，需要有一些方法在维护道路上的所有村庄之间到达，即使路线不像以前那么短。
首席长老想告诉长老理事会，他们每月可以花费的最小金额来维护连接所有村庄的道路。
在上面的地图中，这些村庄被标记为A到I。右边的地图显示了可以维护成本最低的道路，每月维护216 aacms。
你的任务是编写一个程序来解决这些问题。
*
求解思路：最小生成树+prim算法 
（1）首先用邻接矩阵的方式存储该图像，road【i】【j】的值表示第i点到j点的距离。position(char s)函数用于确定字母在字母表中的位置 。 
（2） 从第一个点出发，选取离它最近的一个点，即最小边的一个点，并将选取过的点，做标记，并不在访问 ，将该最短的边累加 。 
（3） 继续扩展 ，重复 （2）的步骤，直到所有点都走过，最短的边的累加就是花费的。 
*
提交状态：AC
*
AC结果：
284K	16MS
*
出错次数：
1次
错误结果：
*/

#include<iostream>
#include<cstring>
using namespace std;
int road[100][100];
int dist[100];
bool visit[100];
char dic[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int position(char s)
{
	int i;
	for(i = 0;;i++)
		if(dic[i] == s)
		return i; 
 } 
int main()
{
	int s,e,n,m,dis,sum;
	char name,node;
	memset(visit,0,sizeof(visit));
	for(int i = 1;i <= 100;i++){
		for(int j = 1;j <= 100;j++)
			road[i][j] = 10000;
			road[i][i] = 0;
	}
	while(cin>>n && n != 0)
	{
		for(int j = 1;j < n;j++)
		{
			cin>>name>>m;
			s=position(name);
			while(m--){
				cin>>node>>dis;
				e=position(node);
				road[e][s]=dis;
				road[s][e]=dis;		
			}
		}
		for(int i = 1;i < n;i++)
		dist[i]=road[1][i];
        visit[1]=1;
        sum = 0;
		for(int i = 1;i < n;i++)
		{
			int max = 10000;
			int rec = -1;
			for(int j = 1;j <= n;j++)
				if(!visit[j]&&dist[j]<max) 
				{
					max = dist[j];
					rec = j;
				}
			sum+=dist[rec];
			visit[rec] = 1;
			for(int j = 1;j <= n;j++)
				if(!visit[j]&&road[rec][j] < dist[j])
					dist[j] = road[rec][j];	
		}
		cout<<sum<<endl;
	}
	return 1;
}









