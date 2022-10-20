/*
问题描述：
两个监狱交换等数量的犯人（不超过一半），有的犯人不能在一个监狱，求最大交换人数
*
求解思路：并查集+动态规划 
（1）利用并查集将两个监狱人员合并，将有关系的人员记录，利用状态转移方程实现动态规划 
（2）init()为初始化函数 ，find(int a)和 merge(int a, int b)函数实现并查集功能。 
（3） 设i为单个监狱总人数的二分之一， 利用状态转移方程递减，直到得到最后的人数。 
*
提交状态：AC
*
AC结果：
440K	297MS
*
出错次数：
1、2次
错误结果：
超时 

*/

#include<iostream>
#include<string.h>
using namespace std;
 
#define MAX 410
 
int cnt1[MAX];
int cnt2[MAX];
int f[MAX];
int dp[MAX / 2][MAX / 2];
int m, r;
int cnt; //记录连通集个数
 
struct P
{
	int a;
	int b;
}p[MAX];
 
//并查集，记录每个连通集两个监狱中有关系的人数
void init() {
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));
	memset(dp, 0, sizeof(dp));
	cnt = 0;
	for (int i = 0; i < MAX; i++)
		f[i] = i;
}
 
int find(int a) {
	return a == f[a] ? a : f[a] = find(f[a]);
}
 
void merge(int a, int b) {
	int fa = find(a);
	int fb = find(b);
	if (fa != fb)f[fa] = fb;
}
int main() {
	int n;
	int a, b;   //记录有关系的犯人
	cin >> n;
	while (n--) {
		cin >> m >> r;
		init();
		for (int i = 0; i < r; i++) {
			cin >> a >> b;
			merge(a, b + m);
		}
		for (int i = 1; i <= m; i++)cnt1[find(i)]++;
		for (int i = m + 1; i <= m * 2; i++)cnt2[find(i)]++;
		for (int i = 1; i <= m * 2; i++) {
			if (cnt1[i] || cnt2[i]) {
				p[cnt].a = cnt1[i];
				p[cnt].b = cnt2[i];
				cnt++;
			}
		}
		//动态规划
		dp[0][0] = 1;
		for (int i = 0; i < cnt; i++)
			for (int j = m / 2; j >= p[i].a; j--)
				for (int k = m / 2; k >= p[i].b; k--)
					if (dp[j - p[i].a][k - p[i].b])dp[j][k] = 1;   //状态转移方程
		int i = m / 2;
		while (!dp[i][i])i--;
		cout << i << endl;
	}
	return 0;
}
