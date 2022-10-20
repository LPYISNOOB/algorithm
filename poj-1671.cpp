/*
问题描述：
有n行诗，每行都有其韵律。求n行诗存在的韵律组合数。 
*
求解思路：第二类Stirling数
（1）第二类Stirling数是把n个元素放入k个等价类的方法数目(每个等价类都不能为空)
(2) 注意到此题的'行数'>='韵律数',可以把'行数'抽象为n个元素,'韵律数'抽象为k个等价类. 
(3)所求即为：把n行放入k个‘韵律’中的方法数( 其中:1=< k <=n )。
(4)状态转移方程为F[ i,  j ]  =  F[ i-1,  j-1 ]  +  F[ i-1,  j ]  *  j 
*
提交状态：AC
*
AC结果：
280K	0MS
*
出错次数：
1次
错误结果：

*/
#include<iostream>
#include<cstdio>
using namespace std;
 
// 变量
int n; // 人数
double F[101][101]; // F[i][j]:表示把i个人装进j个盒子中的方法数(每个盒子都非空)
 
void DP()
{
	// init
	for( int j = 1; j <= 100; ++ j )
		F[1][j] = 0;
	for( int i = 1; i <= 100; ++ i )
		F[i][1] = 1;
 
	// dp
	for( int i = 2; i <= 100; ++ i )
		for( int j = 2; j <= i; ++ j )
			F[i][j] = F[i-1][j-1] + F[i-1][j]*j;
}
 
int main()
{
	DP();
	while( cin >> n && n )
	{
		double res = 0;
		for( int i = 1; i <= n; ++ i )
			res += F[n][i];
		printf( "%d %.0f\n", n, res );
	}
	return 0;
}
