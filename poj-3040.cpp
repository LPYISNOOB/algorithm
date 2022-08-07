/*
����������
��Ϊ��ţ�̲�������¼�Ľ�����ũ��Լ��������ʼÿ������ţ����֧������������
 FJ ��һ�� N (1 <= N <= 20) ��ͬ����Ӳ�ң�����ÿ������Ӳ�Ҿ�����һ����������Ӳ��
 �����磬1 ����Ӳ�ҡ�5 ����Ӳ�ҡ�10 ����Ӳ�Һ� 50 ����Ӳ�ң� Ӳ�ң���
 ʹ�ø�����һ��Ӳ�ң�����ÿ�������� Bessie ֧��һ��������Ǯ C (1 <= C <= 100,000,000)��
 �����������������֧�� Bessie �����������
*
���˼·�����߼���̰�����⡢�ؼ�������Ӳ�ҵ�ѡȡ 
��1�� �кܶ���ȡ������ֻҪ��ֵ����C��ֽ�ң�������һ����֧�� 
��2��С��C����ֵ����Ҫ��� ��ÿ��ѭ��Ѱ��һ����ǰ���ŵ��߷���ֱ��ʣ�µ��ܽ��С��C��
��3���Ӵ�Сȡ�����ܳ���C����ֵ �����ܵ�ʹ�ô�����ֽ�ң�����Ϊ0���������ʱ���� 
��4�� use[MAXN�������ڼ�¼��ǰȡ���ĵ�i����ֵȡ�ĸ�����coin[i].v��coin[i].b�ֱ��ʾӲ�ҵ���ֵ������ 
��5���ҵ���ǰȡ����ȡ���ܴ���
*
�ύ״̬��AC
*
AC�����
132K 0MS 

*
���������
3.4��
��������
 
�������ݵķ�Χ��׼ȷ��֪�������ݵķ�Χ������ֵ���ղ�׼
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

