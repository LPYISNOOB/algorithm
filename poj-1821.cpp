/*
����������
K���˶�N��ľ��Ϳɫ��ÿ���˳�ʼվ��һ��ľ��ǰ�����ظ�����
ÿ�����ֻ��Ϳ������վľ�������l��ľ���һ��ľ��Ҳ��Ϳ������ÿ�����Ϳ��ľ����l,
Ϳһ��ľ��Ĺ�Ǯp��վ��ľ��s������Ⱥ����๲��ö��ٹ�Ǯ
*
���˼·����������dp 
��1��f[i][j]��ʾǰi����Ϳǰj�������ֵ
��2���Ȱ����й�������Si ����������ÿ��������ˢ��ľ��һ������һ��������ˢ��ľ��֮��
��3�� ��j���ʱ������ͷԪ�أ���С��j - L
 �ľ��߳��ӡ�
 (4)��Ҫ��ѯ���о���ʱ����ͷ��Ϊ����

*
�ύ״̬��AC
*
AC�����
6552K	79MS
*
���������
1��
��������
�𰸴��� 

*/

#include<cstdio>
#include<algorithm>

using namespace std; 
struct rec{int L,P,S;}a[110];
int n,m; 
int f[110][16010],q[16010]; 
bool operator <(rec a,rec b){return a.S<b.S;}
int calc(int i,int k){return f[i-1][k]-a[i].P*k;}

int main()
{
	scanf("%d%d",&n,&m); 
	for (int i = 1;i <= m;i++) 
		scanf("%d%d%d",&a[i].L,&a[i].P,&a[i].S);
	sort(a + 1,a + m + 1); 
	for (int i = 1;i <= m;i++){
		int l = 1 ,r = 0; //��ʼ����������
		for (int k = max(0,a[i].S - a[i].L);
			k <= a[i].S - 1; k++){
			while (l <= r && calc(i,q[r]) <= calc(i,k)) 
				r--; //�����¾��ߣ�ά����β������
			q[++r] = k; 
		}
		for (int j = 1;j <= n;j ++){
			f[i][j] = max(f[i-1][j],f[i][j-1]);		//����ˢʱ��ת��
			if (j >= a[i].S) {
				while (l <= r&&q[l] < j-a[i].L) 
					l ++; //�ų���ͷ���Ϸ�����
				if (l <= r) 
					f[i][j] = max(f[i][j],calc(i,q[l]) + a[i].P * j); //���зǿ�ʱ��ȡ��ͷ����״̬ת��
			}
		}
	}
	printf("%d",f[m][n]); 
}



