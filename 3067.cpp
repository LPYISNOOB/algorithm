/*
问题描述：
日本是一个高大的岛屿，东海岸有N个城市，西海岸有M个城市（M <=1000，N<=1000）。
K高速公路将被建造。每个海岸的城市编号为1，2，...从北到南。每条高速公路都是直线，将东海岸的城市与西海岸的城市连接起来。
。总和的主要部分由高速公路之间的交叉口数量决定。
在一个地点最多有两条高速公路交叉。编写一个程序来计算高速公路之间的交叉点数量
求解思路：
（1）创建名为road的数据结构，有整形w，e表示东部和西部。
（2）依次写入东西部的数量，路线的数量，以及信息存入road中。
（3）利用算法库中的函数，将road进行排序
（4）把road.e赋值给A[]数组，对其进行归并排序，归并排序的反转次数（逆序数）就表示路线的交点数量。
提交状态：AC

AC结果：5348K	454MS

出错次数：
十余次
错误结果：
刚开始把题目想的过于简单，没有用到排序思想，导致一直超时，无法顺利提交；
测试数据的范围不准确认知，对数据的长度类型把握不准。


*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int A[1000000];
int T[1000000];
long long cnt;
void mergesort(int p,int r)
{
	if(p == r)return; 
	int mid = (p+r)>>1;
	mergesort(p,mid);
	mergesort(mid+1,r);
	long long local = 0;
	int i = p,j = mid+1;
	for(int k = p;k <= r;k++){
		if(i <= mid && j <= r){
			if(A[i] > A[j]) 
				local++, T[k] = A[j++];
			else 
				cnt += local, T[k] = A[i++];
		}
		else if(i <= mid) 
			cnt += local, T[k] = A[i++];
		else 
			T[k] = A[j++];
	}
	for(int k = p;k <= r;k++)
		A[k] = T[k];

}
struct Road{
	int w,e;
};
bool operator<(const Road &r1, const Road &r2){
	if(r1.w == r2.w) return r1.e < r2.e;
	else return r1.w < r2.w;
}
Road roads[1000000];

int main()
{
	int t;
	scanf("%d",&t);
	for(int q = 1;q <= t;q++){
		int n, m, k;
		scanf("%d %d %d",&n,&m,&k);
		for(int i = 0;i < k;i++)
			scanf("%d%d",&roads[i].w, &roads[i].e);
		sort(roads, roads+k);
		for(int i = 0;i < k;i++)
			A[i] = roads[i].e;
		cnt = 0;
		mergesort(0,k-1);
		printf("Test case %d: %lld\n",q,cnt);
	}
}








