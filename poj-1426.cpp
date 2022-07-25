/*
问题描述：
给定一个正整数n，编写一个程序来找出n的非零倍数m，其十进制表示只包含数字0和1。
您可以假设 n 不大于 200，并且有一个包含不超过 100 个小数位的相应 m。
对于输入中的每个值 n，打印一行包含相应的 m 值。
m 的十进制表示形式不得包含超过 100 位数字。如果给定值 n 有多个解，则其中任何一个都是可以接受的。
*
求解思路：
（1）当n不为0时，就会输出其对应的m值 
（2）利用dfs算法dfs(1,1)表示 第一层当前值为1 
（3）如果当前值能被n整除就会将ans赋值为当前值，即当前dfs的结果 ，并返回 
（4）或者step达到19就会返回，该值为最大层数的值 
（5）每次搜索有两种方法一种为乘10即在尾部加一个0，或者乘10+1表示尾部＋1. 
	   
*
提交状态：AC
*
AC结果：
132K	110MS
*
出错次数：
一两次
错误结果：
刚开始对回溯算法掌握的不牢固，对一些C++自带函数认识不全，不懂得使用方法。 
测试数据的范围不准确认知，对数据的范围和特殊值把握不准

*/
#include<cstdio>
using namespace std;
int n;
bool suc;
unsigned long long ans;
void DFS(unsigned long long now,int step)
{
	if(now%n == 0){
		ans = now;
		suc = true;
		return;
	}
	if(step == 19||suc) 
		return;
	DFS(now*10,step+1);
	DFS(now*10+1,step+1);
}
int main()
{
	while(scanf("%d",&n),n)
	{
		ans = suc = 0;
		DFS(1,1);
		printf("%llu\n",ans);
	}
	return 0;
}
