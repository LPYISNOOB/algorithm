/*
����������
��������֮����ţ�ÿ�����嶼�����Լ����ţ����ý��棬��˳�����е��������壬���β�ͬ���ŵĳɱ�����������֮��ĸ߶Ȳ 
*
���˼·����άdp 
��1�� ����ɽ�µ���������������άdp��������άdp�Ƚ���д���������ǿ����ö�άdp���������Ҫ������ԣ����ҳ����е���Сֵ���ɡ� 
��2�� ����dp����ֱ���xy/xz/zy����ʾ��״̬ת�Ʒ���Ϊxz[i][j]=min(min(xz[i-1][j+1],xz[i-1][j]),xz[i][j+1])+abs(a[i]-c[j])��
��3�� ����������������ϲ���ʱ�����ڲ��ܽ�������ֻ�м����������������һ���ҳ���Сֵ���������ĳɱ��� 
 
*
�ύ״̬��AC
*
AC�����
448K	79MS
*
���������
1��2 
��������

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
