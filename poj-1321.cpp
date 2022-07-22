/*
问题描述：
在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。
要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，
请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
*
求解思路：row表示行，col表示列，对棋盘进行深度搜索 
（1）把每个棋盘读取在chess数组中 
（2）对每个棋盘进行dfs搜索 
（3）只有在chess[row][i] == '#'时可以选择放或不放 ，每一行都有这两种选择 
（4）当行数大于n时dfs结束 或k等于要放的棋子数时结束 
	   
*
提交状态：AC
*
AC结果：
220K	141MS
*
出错次数：
3次
错误结果：
刚开始对回溯算法掌握的不牢固，对一些C++自带函数认识不全，不懂得使用方法。 
测试数据的范围不准确认知，对数据的范围和特殊值把握不准



*/
#include <iostream>
#include <cstring>
using namespace std;

const int ROW = 10;
const int COL = 10;

int book[COL];
char chess[ROW][COL];
int step, n;
long long  sum;


void DFS(char chess[][COL], int row,int k) {
	if (row > n)
		return;
	if (k == step) {
		sum++;
		return;
	}
		
	for (int j = 1; j <= 2; j++) {
		if (j == 1)
			DFS(chess, row + 1, k);
		if (j == 2) {
			for (int i = 0; i < n; i++) {
				if (book[i] == 0 && chess[row][i] == '#') {
					book[i] = 1;
					DFS(chess, row + 1, k + 1);
					book[i] = 0;
				}
			}
		}
	}
}


int main() {
	while (cin >> n >> step) {
		sum = 0;
		cin.get();
		if (n == -1 && step == -1)
			break;
		for (int i = 0; i < n; i++)
			cin >> chess[i];
	
			DFS(chess, 0, 0);
		


		cout << sum << endl;
	}
}
