/*
问题描述：
K个人对N块木板涂色，每个人初始站在一块木板前（不重复），
每人最多只能涂包含所站木板的连续l个木板或一个木板也不涂。给出每人最多涂的木块数l,
涂一快木板的工钱p，站的木板s。求这群人最多共获得多少工钱
*
求解思路：单调队列dp 
（1）f[i][j]表示前i个人涂前j个的最大值
（2）先把所有工匠按照Si 排序，这样，每个工匠粉刷的木板一定在上一个工匠粉刷的木板之后。
（3） 当j变大时，检查队头元素，把小于j - L
 的决策出队。
 (4)需要查询最有决策时，队头即为所求。

*
提交状态：AC
*
AC结果：
6552K	79MS
*
出错次数：
1次
错误结果：
答案错误 

*/

#include<cstdio>
#include<algorithm>

using namespace std; 
struct rec{int L,P,S;}a[110];
int n,m; 
int f[110][16010],q[16010]; 
bool operator <(rec a,rec b){return a.S<b.S;}
int calc(int i,int k){return f[i-1][k]-a[i].P*k;}

int main()
{
	scanf("%d%d",&n,&m); 
	for (int i = 1;i <= m;i++) 
		scanf("%d%d%d",&a[i].L,&a[i].P,&a[i].S);
	sort(a + 1,a + m + 1); 
	for (int i = 1;i <= m;i++){
		int l = 1 ,r = 0; //初始化单调队列
		for (int k = max(0,a[i].S - a[i].L);
			k <= a[i].S - 1; k++){
			while (l <= r && calc(i,q[r]) <= calc(i,k)) 
				r--; //插入新决策，维护队尾单调性
			q[++r] = k; 
		}
		for (int j = 1;j <= n;j ++){
			f[i][j] = max(f[i-1][j],f[i][j-1]);		//不粉刷时的转移
			if (j >= a[i].S) {
				while (l <= r&&q[l] < j-a[i].L) 
					l ++; //排除队头不合法决策
				if (l <= r) 
					f[i][j] = max(f[i][j],calc(i,q[l]) + a[i].P * j); //队列非空时，取队头进行状态转移
			}
		}
	}
	printf("%d",f[m][n]); 
}



