/*
问题描述：
农民约翰被告知了一头逃亡牛的位置，并希望立即抓住她。
他从数字线上的点 N（0 ≤ N ≤ 100，000）开始，奶牛位于同一数字线上的点 K（0 ≤ K ≤ 100，000）。
农民约翰有两种交通方式：步行和传送。
*行走：FJ可以在一分钟内
从任何点X移动到X点 - 1或X + 1*传送：FJ可以在一分钟内从任何点X移动到X点×2点。
如果母牛没有意识到它的追求，根本没有动，那么农夫约翰需要多长时间才能取回它？
*
求解思路：利用bfs的思想进行求解 ，答案就等于bfs 的深度  
（1）初始化vis数组用于表示路径点的状态 
（2）为n和k赋值，分别表示农民和奶牛的位置 
（3）d数组表示到每个点要走的步数 
（4）利用队列进行bfs搜索， 每一步都有三种选择，从当前节点退一步进一步或者装送至乘二的位置， 当所处的位置等于m时返回值
（5）输出d[m]，即到m位置要走的步数。 
    
	   
*
提交状态：AC
*
AC结果：
2220K	157MS
*
出错次数：
十余次
错误结果：
刚开始对回溯算法掌握的不牢固，对一些C++自带函数认识不全，不懂得使用方法。 
测试数据的范围不准确认知，对数据的范围和特殊值把握不准

*/
#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;
int n,m;
int vis[200001];
queue<int> q;
int d[200001];
void bfs(int n){
	    q.push(n);
	    d[n] = 0;
     	while (!q.empty()){
     		int l = q.front();
     		    q.pop();
     		if(l == m) return ; 
     		int t = l+1;
     		if(t >= 0 && t <= 200000 && vis[t] != 1){
     		     vis[t] = 1;
				  q.push(t);
				  d[t] = d[l]+1;
			 }
		     t = l-1;
		    if(t >= 0 && t <= 200000 && vis[t] != 1){
		    	vis[t] = 1;
		    	q.push(t);
		    	d[t] = d[l]+1;
			}
			t = 2*l;
			 if(t >= 0 && t <= 200000 && vis[t] != 1){
		    	vis[t] = 1;
		    	q.push(t);
		    	d[t] = d[l]+1;
			}
		 }
    return;
} 
int main(){
	memset(vis,0,sizeof(vis));
	cin>>n>>m;
	bfs(n);
	cout<<d[m]<<endl;
}

