/*
问题描述：
从n个人中选出m个人，选法为控方满意度之和s1与辩方满意度之和s2的差的绝对值最小，
若有多种方案，则选择控方满意度之和s1与辩方满意度之和s2的和最大的一组，先输出这是第几组数据，
下一行分别输出选择出来的方案中的控方满意度之和s1与辩方满意度之和s2。
最后一行输出选择的人的编号，按从小到大的顺序排列。

*
求解思路：
（1）用一个二维dp[i][k]，第一维i代表已经选择了的人数，即1——m，
第二维k代表枚举出来的可能出现的控方满意度之和s1与辩方满意度之和s2的差，
不过这个差可能为负，即数组的第二维可能为负，因此我们可以让它向左偏移一下，
具体实现看代码，这个二维dp的值就代表控方满意度之和s1与辩方满意度之和s2的和；
则dp[i][k]可由dp[i-1][x]得来的条件是存在某个还没被选择的候选人j使得k=x+v[j]。
（2） v[j]数组代表第j个人的控方与辩方满意度之差，
s[j]数组代表第j个人的控方与辩方满意度之和。
（3）这个时候我们就可以枚举1——n中的满足这个条件的j来动态规划。
输出要求输出选择的人的编号，因此我们用一个path数组来存储选择的人的编号，
path[i][k]的值为当前所选人的编号j，i代表这是选择的第几个人，与上文的i意义相同，
k也与上文的意义相同。这时倒数第二个人的编号就是path[i-1][k-v[path[i][k]]],
依次推回去就可得到选择的所有人的编号。 
	   
*
提交状态：AC
*
AC结果：
376K	16MS
*
出错次数：
3/4次
错误结果：
超时 

*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define LL long long
#define MAX 1000005
#define inf 99999999999
#define mod 1000000007
using namespace std;
 
int dp[25][1000],path[25][1000],f[25],v[205],s[205];
int main()
{
    int n,m,ans,i,j,k,a,b,t1,t2;
    ans = 0;
    while(scanf("%d %d",&n,&m) != EOF)
    {
        if(n == 0 && m == 0)
            break;
        ans++;
        for(i = 1;i <= n;i++)
        {
            scanf("%d %d",&a,&b);
            v[i] = a-b;
            s[i] = a+b;
        }
        memset(dp,-1,sizeof(dp));
        memset(path,-1,sizeof(path));
        dp[0][400] = 0;
        for(i = 0;i < m;i++)//已选人的个数
        {
            for(k = 0;k <= 800;k++)//辩方和与控方和之差
            {
                if(dp[i][k] >= 0)
                {
                    for(j = 1;j <= n;j++)//枚举所有人，选择满足条件的人
                    {
                        if(dp[i][k] + s[j]>dp[i+1][k+v[j]])
                        {
                            t1 = i;
                            t2 = k;
                            while(t1>0&&path[t1][t2] != j)//检查j在之前是否被选择过
                            {
                                t2 -= v[path[t1][t2]];
                                t1--;
                            }
                            if(t1 == 0)
                            {
                                dp[i+1][k+v[j]] = dp[i][k]+s[j];
                                path[i+1][k+v[j]] = j;
                            }
                        }
                    }
                }
            }
        }
        i = 400;//偏移了400；
        j = 0;
        while(dp[m][i+j] < 0 && dp[m][i-j] < 0)//找到与偏移值绝对值之差最小的k，即找到辩方和与控方和之差绝对值最小的k。
        {
            j++;
        }
        if(dp[m][i+j] > dp[m][i-j])
            k = i+j;
        else
            k = i-j;
        printf("Jury #%d\n",ans);
        printf("Best jury has value %d for prosecution and value %d for defence:\n",(k-400+dp[m][k])/2,(dp[m][k]-k+400)/2);
        //（k-400）为辩方和与控方和之差，dp[m][k]为辩方和与控方和之和。通过简单数学计算就可分别得出辩方和与控方和
        for(i = 1;i <= m;i++)//用path推出被选择的人的编号。
        {
            f[i] = path[m-i+1][k];
            k -= v[f[i]];
        }
        sort(f+1,f+1+m);
        for(i = 1;i <= m;i++)
        {
            printf(" %d",f[i]);
        }
        printf("\n\n");
    }
 
    return 0;
}
 
