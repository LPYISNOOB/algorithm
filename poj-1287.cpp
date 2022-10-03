/*
问题描述：
您被指派设计广域中某些点之间的网络连接。您将获得该区域中的一组点，
以及一组可能连接点对的电缆的可能路线。对于两点之间的每个可能路径，
将为您提供连接该路径上的点所需的电缆长度。请注意，在两个给定点之间可能存在许多可能的路线。
假设给定的可能路线（直接或间接地）连接该地区的每个两个点。
您的任务是为该区域设计网络，以便每两个点之间有一个连接（直接或间接）（
即，所有点都相互连接，但不一定通过直接电缆），并且所用电缆的总长度最小。
输入文件由许多数据集组成。每个数据集定义一个必需的网络。集合的第一行包含两个整数：
第一行定义给定点的数 P，第二行定义点之间给定路由的 R 数。以下 R 线定义点之间的给定路径，
每条线给出三个整数：前两个数字标识点，第三个数字表示路径的长度。数字之间用空格分隔。
只给出一个数字 P=0 的数据集表示输入的结束。数据集用空行分隔。
最大点数为 50。给定路由的最大长度为 100。可能的路线数量是无限的。
节点由介于 1 和 P（包括 1 和 P）之间的整数标识。两点 i 和 j 之间的路径可以给出为 i j 或 j i。
*
求解思路：邻接表+克鲁斯卡尔算法 
（1）将所有的边用邻接表的方法存储起来 ，只保留连接两点的线缆长度最短的边 
（2）把n条边从小到大保存起来，从小到大每次提取一条边，如果形成成闭环就去掉这条边，知道形成的树能够连接所有的点。 
*
提交状态：AC
*
AC结果：
304K	79MS
*
出错次数：
1.2次
错误结果：


*/
#include <iostream>
#include <algorithm>
#define MAX 55

using namespace std;

int father[MAX];    //记录各节点的父节点
int m[MAX][MAX];    //存储采用所用线缆后的图的邻接表
int cmax;       

struct edge
{
    int x,y;
    int w;
}e[MAX * MAX / 2];  //用来存储各个边的信息，x点至y点的权值为w

int find_set(int a) //查找a所在的集合，回溯时顺便压缩路径
{
    if(a != father[a])
    {
        father[a] = find_set(father[a]);
    }
    return father[a];
}

void Union(int x,int y,int w)   //合并x和y所在的集合，并用cmax记录所有边的权值之和
{
    if(x == y)  return;
    father[y] = x;
    cmax += w;
}

bool cmp(edge a,edge b)   //非降序排序排序函数
{
    return a.w < b.w;
}

int main()
{
    int n,r,i,j,s,t,tmp,k;
    while(scanf("%d%d",&n,&r) != EOF && n!= 0)
    {
        k = 0;
        cmax = 0;
        memset(m,-1,sizeof(m));     //初始化数组
        if(r == 0)      //如果r == 0，直接下次循环
        {
            cout << 0 << endl;
            continue;
        }
        for(i = 0;i < r;i++)
        {
            cin >> s >> t >> tmp;   //输入线缆的数据，连接s和t权值为tmp的线缆
            if(s > t)   //只对m的上三角信息进行存储
            {
                int temp = s;
                s = t;
                t = temp;
            }
            if(m[s-1][t-1] == -1 || m[s-1][t-1] > tmp) m[s-1][t-1] = tmp;   //只保留连接两点的线缆长度最短的边
        }
        //Kruskal算法
        for(i = 0;i < n;i++)
        {
            father[i] = i;
            for(j = 0;j < n;j++)
            {
                if(i < j )
                    if(m[i][j] != -1)
                    {
                        e[k].x = i;
                        e[k].y = j;
                        e[k].w = m[i][j];
                        k++;
                    }
            }
        }
        sort(e,e + k,cmp);
        for(i = 0;i < k;i++)
        {
            Union(find_set(e[i].x),find_set(e[i].y),e[i].w);
        }
        cout << cmax << endl;
    }
    return 0;
}
