/*
����������
��������������������и���r��ͬʱ����Ҳ����r���Ϳ��԰�������������������һ��rƥ�䡣
����ÿһ��aƥ�䣬����Ҫ��ǡ��һ��bƥ����֮�ཻ������a������b��
����ƥ�䲻�ܹ���һ�����֡�
*
���˼·��dp
��1����ȡ���ݣ���ʼ��dp��dp[i][j]��ʾA��ǰi����B��ǰj�������ƥ��
��2��״̬ת�Ʒ���Ϊdp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i][j-1]))�� 
if(x[i] == y[j])//��Ȳ���ƥ�� ��������ȣ���ô�Ϳ�����A���B��֮ǰ��������ȥ�ң�����иպ÷ֱ�������������ȵģ��Ϳ�������ƥ�䡣 
dp[i][j] = max(dp[i][j],dp[p-1][q-1]+2)����Ϊ��������ĶΣ�����ÿ�Σ�2�� 
 (3) dp��������һλ���Ǵ𰸣����ƥ�䣩�� 
 
*
�ύ״̬��AC
*
AC�����
228K	0MS
*
���������
1��
��������
������� 
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
                if(x[i] == y[j])//��Ȳ���ƥ�� 
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
