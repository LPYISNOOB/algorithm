/*
问题描述：
三个宗族之间搭桥，每个宗族都得有自己的桥，不得交叉，按顺序排列的三个宗族，海拔不同，桥的成本就是两宗族之间的高度差。 
*
求解思路：三维dp 
（1） 三个山崖的桥梁分配所以三维dp，由于三维dp比较难写，所以我们可以用二维dp来解决，需要两两配对，再找出其中的最小值即可。 
（2） 三个dp数组分别用xy/xz/zy来表示，状态转移方程为xz[i][j]=min(min(xz[i-1][j+1],xz[i-1][j]),xz[i][j+1])+abs(a[i]-c[j])。
（3） 将这三组合起来，合并的时候由于不能交叉所以只有几种情况，从三组中一次找出最小值，就是最后的成本。 
 
*
提交状态：AC
*
AC结果：
448K	79MS
*
出错次数：
1、2 
错误结果：

*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int n,m,p,a[150],b[150],c[150],xz[150][150],xy[150][150],yz[150][150],ans,tt;
void read()
{
    scanf("%d%d%d",&m,&n,&p);
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    for(int i = 1;i <=m ;i++) scanf("%d",&b[i]);
    for(int i = 1;i <= p;i++) scanf("%d",&c[i]);
    for(int i = 0;i < 150;i++)
        for(int j = 0;j<150;j++)
            xz[i][j] = xy[i][j] = yz[i][j]=999999;
    ans = 999999;
}

void go()
{
    xz[0][p+1] = 0;
    for(int i = 1;i <= n;i++)
        for(int j = p;j >= 1;j--)
            xz[i][j] = min(min(xz[i-1][j+1],xz[i-1][j]),xz[i][j+1])+abs(a[i]-c[j]);
    xy[n+1][0] = 0;
    for(int i = n;i >= 1;i--)
        for(int j = 1;j <= m;j++)
            xy[i][j] = min(min(xy[i+1][j-1],xy[i+1][j]),xy[i][j-1])+abs(a[i]-b[j]);
    yz[m+1][0] = 0;
    for(int i = m;i >= 1;i--)
        for(int j = 1;j <= p;j++)
            yz[i][j] = min(min(yz[i+1][j-1],yz[i+1][j]),yz[i][j-1])+abs(b[i]-c[j]);
    for(int i = 0;i <= n+1;i++)
        for(int j = 0;j <= m+1;j++)
            for(int k = 0;k <= p+1;k++)
            {
                ans = min(ans,xy[i][j]+xz[i][k]+yz[j][k]);
                ans = min(ans,xy[i][j]+xz[i][k]+yz[j+1][k]);  
                ans = min(ans,xy[i+1][j]+xz[i][k]+yz[j][k]);  
                ans = min(ans,xy[i][j]+xz[i][k+1]+yz[j][k]);
                ans = min(ans,xy[i+1][j]+xz[i][k]+yz[j+1][k]);  
                ans = min(ans,xy[i][j]+xz[i][k+1]+yz[j+1][k]);  
                ans = min(ans,xy[i+1][j]+xz[i][k+1]+yz[j][k]);
                ans = min(ans,xy[i+1][j]+xz[i][k+1]+yz[j+1][k]);
            }
    printf("%d\n",ans);
}

int main()
{
    scanf("%d",&tt);
    while(tt--)
    {
        read();
        go();
    }
    return 0;
}
