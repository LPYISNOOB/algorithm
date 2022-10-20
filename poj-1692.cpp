/*
问题描述：
两组数，如果上面那组有个数r，同时下面也有数r，就可以把两组数连起来，称作一个r匹配。
对于每一个a匹配，必须要有恰好一个b匹配与之相交，并且a不等于b。
两个匹配不能共用一个数字。
*
求解思路：dp
（1）读取数据，初始化dp，dp[i][j]表示A组前i个和B组前j个的最大匹配
（2）状态转移方程为dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i][j-1]))， 
if(x[i] == y[j])//相等不会匹配 ，如果不等，那么就可以在A组和B组之前的数字中去找，如果有刚好分别和最后两个数相等的，就可以增加匹配。 
dp[i][j] = max(dp[i][j],dp[p-1][q-1]+2)，因为两个交叉的段，所以每次＋2， 
 (3) dp数组的最后一位就是答案（最大匹配）。 
 
*
提交状态：AC
*
AC结果：
228K	0MS
*
出错次数：
1次
错误结果：
编译错误 
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
 
const int MAXN = 110;
int x[MAXN],y[MAXN];
int dp[MAXN][MAXN];
int main() {
    int t; 
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        for(int i = 1;i <= n;i++)
            scanf("%d",x+i);
        for(int i = 1;i <= m;i++)
            scanf("%d",y+i);
        dp[0][0] = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
                if(x[i] == y[j])//相等不会匹配 
                    continue;
                int flag = 1;
                for(int p = i-1;p >= 1&&flag;p--){
                    for(int q = j-1;q >= 1;q--){
                        if(x[p] == y[j]&&x[i] == y[q]){
                            dp[i][j] = max(dp[i][j],dp[p-1][q-1]+2);
                            flag = 0;
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n",dp[n][m]);
    }
}
