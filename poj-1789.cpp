/*
问题描述：
先进货运有限公司使用不同类型的卡车。一些卡车用于蔬菜运输，其他卡车用于家具或砖块。
该公司有自己的代码来描述每种类型的卡车。代码只是一个由七个小写字母组成的字符串
（每个位置上的每个字母都有非常特殊的含义，但这对于此任务并不重要）。在公司历史的开始，
只使用一种卡车类型，但后来从它派生出其他类型，然后从新类型派生出另一种类型，依此类推。

今天，ACM足够富有，可以付钱给历史学家来研究它的历史。历史学家试图找出的一件事是所谓的推导计划 -
 即卡车类型是如何推导的。他们将卡车类型的距离定义为卡车类型代码中具有不同字母的位置数。
 他们还假设每个卡车类型都恰好是从另一种卡车类型派生的（除了第一个卡车类型，它不是从任何其他类型派生的）。
 然后，派生计划的质量被定义为
1/Σ（吨o，吨d）d（吨o，td）
其中，总和遍历派生计划中的所有类型对，使得 to 是原始类型，td 是从它派生的类型，d（to，td） 是类型的距离。
既然历史学家失败了，你就要写一个程序来帮助他们。给定卡车类型的代码，您的程序应找到尽可能高质量的派生计划
*

求解思路：构建最小生成树+普里姆算法 （加点法） 
（1）首先将所有数据读取到ch数组中；初始化fd数组表示后续查找时是否到此点；num数组表示下一最近的点的最短距离 
（2）首先从第一个点开始，将该点到每个点的最小距离保存到num数组中 ，num数组中存放的是到每条边的最短距离 
（3）紧接着将当前的点位置设置成这个路程最短的目标点，重复之前的操作，直到遍历num数组之后，
实在是找不到一个还没有去过的点，那就说明最小生成树完成了，退出循环。
	   
*
提交状态：AC
*
AC结果：
297ms 169kb 
*
出错次数：
1次
错误结果：
对题意理解不清晰，错误理解了后续卡车的生成原理。 

*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
char ch[20005][8];
bool fd[2005];
int num[2005];
int main(){
	int n;
	while(cin>>n)
	{
		for(int i = 0;i < 2005;i++)num[i] = 0x7fffffff;
		memset(fd,false,sizeof(fd));
		if(n == 0)break;
		int ans = 0;
		for(int i = 0;i < n;i++)
		{
			cin>>ch[i];
		}
	    int temp = 0;
		while(1)
		{
			fd[temp] = true;
			for(int i = 0;i < n;i++)
			{
				if(fd[i])continue;
				int t = 0;
				for(int j = 0;j < 7;j++)
				{
					if(ch[i][j] != ch[temp][j]) t++;
				}
				num[i] = min(num[i],t); 
			}
	  	    int zz = -1;
			int MIN = 0x7fffffff;
			for(int i = 0;i < n;i++)
			{
				if(!fd[i])
				{
					if (num[i] < MIN)
					{	
						MIN = num[i];
						zz = i;
					}
				}
			}
			if(zz == -1)break;
			temp = zz;
			ans += MIN;
		}	
		cout<<"The highest possible quality is 1/" <<ans<<"."<<endl;
	}	
	return 0;
}
