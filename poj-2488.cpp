/*
问题描述：
骑士厌倦了一次又一次地看到相同的黑白方块，并决定
环游世界。每当骑士移动时，它都是一个方向上的两个正方形和一个垂直于此的正方形。
骑士的世界是他赖以生存的棋盘。我们的骑士住在一个棋盘上，它的面积比普通的8* 8棋盘小，但它仍然是矩形的。
你能帮助这个冒险的骑士制定旅行计划吗？
找到一条路径，让骑士访问每个方块一次。骑士可以在棋盘的任何方块上开始和结束。
*
求解思路：首先要走完全程我们显然可以搜索，这道题普通的dfs就足够了，但是本题要按字典序输出结果
（1）把每个位置对应的字符存储起来，由于p*q小于26，无法确定pq范围所以都按26来取 
（2）step表示路径，vis表示是否走过  ，check函数表示是否符合继续探索的条件 
（3）x从上到下，y从左到右进行变化，就可以满足字典序，dfs结束的条件是跑完所有的点，每次跑完都需要回溯 ，如果找不到路就要把step还原
（4）利用dfs，如果能走完，返回true，输出step 


*
提交状态：AC
*
AC结果：

*
出错次数：
十余次
错误结果：
对排列顺序的不理解，刚开始不明白字母的使用方法和意义 
刚开始对回溯算法掌握的不牢固，对一些C++自带函数认识不全，不懂得使用方法。 
测试数据的范围不准确认知，对数据的范围和特殊值把握不准
*/

#include<iostream>
#include<string.h>
#include<string>
using namespace std;

#define MAX 30
#define ll int

ll dx[8] = { -2,-2,-1,-1,1,1,2,2 }, dy[8] = { -1,1,-2,2,-2,2,-1,1 };
ll w, l, vis[MAX][MAX];
string s[MAX][MAX], step;

bool check(ll x, ll y) {
	if (x <= 0 || x > l || y <= 0 || y > w || vis[x][y])return false;
	return true;
}

ll dfs(ll x, ll y, ll cnt) {
	step += s[x][y];
	vis[x][y] = 1;
	if (cnt + 1 == l * w) return true;
	for (int i = 0; i < 8; i++) {
		ll xx = x + dx[i], yy = y + dy[i];
		if (check(xx, yy)) {
			if (dfs(xx, yy, cnt + 1)) return true;
			vis[xx][yy] = 0; 
		}
	}

	step.erase(step.size() - 2, 2);
	return false;
}

int main() {
	int m; cin >> m;
	for (int i = 1; i <= 26; i++) {
		for (int j = 1; j <= 26; j++) {
			s[i][j] = (i - 1 + 'A');
			if (j >= 10) s[i][j] += j / 10 + '0';
			s[i][j] += j % 10 + '0';
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("Scenario #%d:\n", i);
		cin >> w >> l; 
		ll sign = 0;
		for (int j = 1; j <= l && !sign; j++) {
			for (int k = 1; k <= w && !sign; k++) {
				step.clear();
				memset(vis, 0, sizeof(vis));
				if (dfs(j, k, 0)) sign = 1;
			}
		}
		if (sign) cout << step << endl;
		else cout << "impossible" << endl;
		cout << endl;
	}
}

