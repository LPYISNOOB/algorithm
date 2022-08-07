/*
问题描述：
作为对牛奶产量创纪录的奖励，农夫约翰决定开始每周向奶牛贝西支付少量津贴。
 FJ 有一组 N (1 <= N <= 20) 不同面额的硬币，其中每个面额的硬币均分下一个更大面额的硬币
 （例如，1 美分硬币、5 美分硬币、10 美分硬币和 50 美分硬币） 硬币）。
 使用给定的一组硬币，他想每周至少向 Bessie 支付一定数量的钱 C (1 <= C <= 100,000,000)。
 请帮助他计算他可以支付 Bessie 的最大周数。
*
求解思路：更高级的贪心问题、关键问题是硬币的选取 
（1） 有很多种取法首先只要面值大于C的纸币，都可以一次性支付 
（2）小于C的面值就需要组合 、每次循环寻找一个当前最优的走法，直到剩下的总金额小于C、
（3）从大到小取，不能超过C的面值 、可能地使用大面额的纸币，数量为0或不能再组合时结束 
（4） use[MAXN数组用于记录当前取法的第i种面值取的个数、coin[i].v、coin[i].b分别表示硬币的面值和数量 
（5）找到当前取法能取的总次数
*
提交状态：AC
*
AC结果：
132K 0MS 

*
出错次数：
3.4次
错误结果：
 
测试数据的范围不准确认知，对数据的范围和特殊值把握不准
*/

#include<cstdio>                             
#include<cstring>                           
#include<algorithm>
using namespace std;
const long INF=9999999;
const int MAXN=35;
int use[MAXN];                             
struct Coin{
    int b,v;
}coin[MAXN];
int cmp(const Coin &a,const Coin &b){
    return a.v<b.v;
}
int main()
{
    int N,C,m;
    while(scanf("%d%d",&N,&C)!=EOF){
        for(int i=0;i<N;i++)
            scanf("%d%d",&coin[i].v,&coin[i].b);
        sort(coin,coin+N,cmp);
        int ans=0;
        for(int i=N-1;i>=0;i--){         
            if(coin[i].v>=C){
                ans+=coin[i].b;
                coin[i].b=0;
            }
        }
        while(true){                       
            int sign=0;                   
            long cnt=C;
            memset(use,0,sizeof(use));
            for(int i=N-1;i>=0;i--){        
                if(coin[i].b){              
                    int k=cnt/coin[i].v;
  					m=min(k,coin[i].b);     
                    cnt-=m*coin[i].v;
                    use[i]=m;
                    if(cnt==0){
                        sign=1;break;      
                    }
                }
            }
            if(cnt>0){
                for(int i=0;i<N;i++){      
                    while(coin[i].b>use[i]){
                        cnt-=coin[i].v;
                        use[i]++;
                        if(cnt<=0){
                            sign=1;break;
                        }
                    }
                    if(sign)break;
                }
            }
            if(!sign)break;
            m=INF;
            for(int i=0;i<N;i++){
                if(use[i])                  
  					m=min(m,coin[i].b/use[i]);
            }
            ans+=m;
            for(int i=0;i<N;i++){
                if(use[i])
                    coin[i].b-=m*use[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

