/*
����������
�������������������ķ��ˣ�������һ�룩���еķ��˲�����һ������������󽻻�����
*
���˼·�����鼯+��̬�滮 
��1�����ò��鼯������������Ա�ϲ������й�ϵ����Ա��¼������״̬ת�Ʒ���ʵ�ֶ�̬�滮 
��2��init()Ϊ��ʼ������ ��find(int a)�� merge(int a, int b)����ʵ�ֲ��鼯���ܡ� 
��3�� ��iΪ���������������Ķ���֮һ�� ����״̬ת�Ʒ��̵ݼ���ֱ���õ����������� 
*
�ύ״̬��AC
*
AC�����
440K	297MS
*
���������
1��2��
��������
��ʱ 

*/

#include<iostream>
#include<string.h>
using namespace std;
 
#define MAX 410
 
int cnt1[MAX];
int cnt2[MAX];
int f[MAX];
int dp[MAX / 2][MAX / 2];
int m, r;
int cnt; //��¼��ͨ������
 
struct P
{
	int a;
	int b;
}p[MAX];
 
//���鼯����¼ÿ����ͨ�������������й�ϵ������
void init() {
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));
	memset(dp, 0, sizeof(dp));
	cnt = 0;
	for (int i = 0; i < MAX; i++)
		f[i] = i;
}
 
int find(int a) {
	return a == f[a] ? a : f[a] = find(f[a]);
}
 
void merge(int a, int b) {
	int fa = find(a);
	int fb = find(b);
	if (fa != fb)f[fa] = fb;
}
int main() {
	int n;
	int a, b;   //��¼�й�ϵ�ķ���
	cin >> n;
	while (n--) {
		cin >> m >> r;
		init();
		for (int i = 0; i < r; i++) {
			cin >> a >> b;
			merge(a, b + m);
		}
		for (int i = 1; i <= m; i++)cnt1[find(i)]++;
		for (int i = m + 1; i <= m * 2; i++)cnt2[find(i)]++;
		for (int i = 1; i <= m * 2; i++) {
			if (cnt1[i] || cnt2[i]) {
				p[cnt].a = cnt1[i];
				p[cnt].b = cnt2[i];
				cnt++;
			}
		}
		//��̬�滮
		dp[0][0] = 1;
		for (int i = 0; i < cnt; i++)
			for (int j = m / 2; j >= p[i].a; j--)
				for (int k = m / 2; k >= p[i].b; k--)
					if (dp[j - p[i].a][k - p[i].b])dp[j][k] = 1;   //״̬ת�Ʒ���
		int i = m / 2;
		while (!dp[i][i])i--;
		cout << i << endl;
	}
	return 0;
}
