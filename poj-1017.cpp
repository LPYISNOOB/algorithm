/*
问题描述：
工厂生产相同高度h的方形包装产品，尺寸为1 * 1，2 * 2，3 * 3，4 * 4，5 * 5，6 * 6。
这些产品始终以与产品高度h相同且尺寸为6 * 6的方形包裹交付给客户。
由于费用的原因，工厂和客户的利益是尽量减少将订购的产品从工厂交付给客户所需的包裹数量。
一个好的程序解决了根据订单找到交付给定产品所需的最小包裹数量的问题，将节省大量资金。您被要求制作这样的程序。
*
求解思路：贪心算法 
（1）从大到小考虑每种箱子的情况，当4*4、5*5、6*6不为0时，他们的数量要全部考虑在其中，因为一个箱子不可能容得下两个4*4、5*5、6*6。 
（2）考虑5*5得情况，出去自身的5*5，还余下11个1*1， 
（3）考虑4*4的情况， 出去自身4*4，还余下5个2*2的空间， 若能填满就不剩空间，填不满还剩下1*1的空间 
（4）考虑3*3的情况，一个6*6正好装4个3*3的，所以3*3的数量除四就是3*3需要的数量， 
（5）考虑2*2的情况，有的已经被之前装下，就不做考虑，剩下的除9，就是2*2所需的空间，剩下的是1*1的空间 
（6）考虑1*1的空间，除去之前被装的，除36，累加到结果中。 
*
提交状态：AC
*
AC结果：
220K	16MS
*
出错次数：
4、5次
错误结果：
Running & Judging

*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#define INT_MAX 1<<30
using namespace std;
typedef long long ll;
const int INF = 0x7F;
int n;
int a[7];
bool bl = false;
int ans = 0;
int main()
{
	while (1)
	{
		bl = false;
		ans = 0;
		for (int i = 1; i <= 6; i += 1)
		{
			scanf("%d",&a[i]);
			if(a[i])bl = true;
		}
		if(!bl)break;
		ans += a[6];
		
		ans += a[5];
		if(a[1] <= 11*a[5])a[1] = 0;
		else a[1] -= 11*a[5];
		
		ans += a[4];
		if(a[2] <= 5*a[4]){
			int left = 20*a[4]-a[2]*4;
			if(a[1] <= left)a[1] = 0;
			else a[1] -= left;
			a[2] = 0;
		}
		else {
			int left = 20*a[4]-5*a[4]*4;
			if(a[1] <= left)a[1] = 0;
			else a[1] -= left;
			a[2] -= 5*a[4];
		}
		
		ans += a[3]/4;
		
		a[3] = a[3]%4;
		if(a[3] > 0){
			ans += 1;
			if(a[2] <= 7-a[3]*2){
				int left = 36-a[3]*9-a[2]*4;
				if(a[1] <= left)a[1] = 0;
				else a[1] -= left;
				a[2] = 0; 
			}
			else {
				int left = 36-a[3]*9-(7-a[3]*2)*4;
				if(a[1] <= left)a[1]=0;
				else a[1] -= left;
				a[2] = a[2]-(7-a[3]*2);
			}
			a[3] = 0;
		}
		
		if(a[2] > 0){
			ans += a[2]/9;
			
			a[2] = a[2]%9;
			if(a[2] > 0){
				ans += 1;
				int left = 36-a[2]*4;
				if(a[1] <= left)a[1] = 0;
				else {
					a[1] -= left;
				a[2] = 0;
				}
			}
		}
		
		if(a[1] > 0){
			ans += a[1]/36;
			a[1] = a[1]%36;
			if(a[1] != 0)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
