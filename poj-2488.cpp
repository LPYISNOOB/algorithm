/*
����������
��ʿ�����һ����һ�εؿ�����ͬ�ĺڰ׷��飬������
�������硣ÿ����ʿ�ƶ�ʱ��������һ�������ϵ����������κ�һ����ֱ�ڴ˵������Ρ�
��ʿ����������������������̡����ǵ���ʿס��һ�������ϣ������������ͨ��8* 8����С��������Ȼ�Ǿ��εġ�
���ܰ������ð�յ���ʿ�ƶ����мƻ���
�ҵ�һ��·��������ʿ����ÿ������һ�Ρ���ʿ���������̵��κη����Ͽ�ʼ�ͽ�����
*
���˼·������Ҫ����ȫ��������Ȼ�����������������ͨ��dfs���㹻�ˣ����Ǳ���Ҫ���ֵ���������
��1����ÿ��λ�ö�Ӧ���ַ��洢����������p*qС��26���޷�ȷ��pq��Χ���Զ���26��ȡ 
��2��step��ʾ·����vis��ʾ�Ƿ��߹�  ��check������ʾ�Ƿ���ϼ���̽�������� 
��3��x���ϵ��£�y�����ҽ��б仯���Ϳ��������ֵ���dfs�������������������еĵ㣬ÿ�����궼��Ҫ���� ������Ҳ���·��Ҫ��step��ԭ
��4������dfs����������꣬����true�����step 


*
�ύ״̬��AC
*
AC�����

*
���������
ʮ���
��������
������˳��Ĳ���⣬�տ�ʼ��������ĸ��ʹ�÷��������� 
�տ�ʼ�Ի����㷨���յĲ��ι̣���һЩC++�Դ�������ʶ��ȫ��������ʹ�÷����� 
�������ݵķ�Χ��׼ȷ��֪�������ݵķ�Χ������ֵ���ղ�׼
*/

#include<iostream>
#include<string.h>
#include<string>
using namespace std;

#define MAX 30
#define ll int

ll dx[8] = { -2,-2,-1,-1,1,1,2,2 }, dy[8] = { -1,1,-2,2,-2,2,-1,1 };
ll w, l, vis[MAX][MAX];
string s[MAX][MAX], step;

bool check(ll x, ll y) {
	if (x <= 0 || x > l || y <= 0 || y > w || vis[x][y])return false;
	return true;
}

ll dfs(ll x, ll y, ll cnt) {
	step += s[x][y];
	vis[x][y] = 1;
	if (cnt + 1 == l * w) return true;
	for (int i = 0; i < 8; i++) {
		ll xx = x + dx[i], yy = y + dy[i];
		if (check(xx, yy)) {
			if (dfs(xx, yy, cnt + 1)) return true;
			vis[xx][yy] = 0; 
		}
	}

	step.erase(step.size() - 2, 2);
	return false;
}

int main() {
	int m; cin >> m;
	for (int i = 1; i <= 26; i++) {
		for (int j = 1; j <= 26; j++) {
			s[i][j] = (i - 1 + 'A');
			if (j >= 10) s[i][j] += j / 10 + '0';
			s[i][j] += j % 10 + '0';
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("Scenario #%d:\n", i);
		cin >> w >> l; 
		ll sign = 0;
		for (int j = 1; j <= l && !sign; j++) {
			for (int k = 1; k <= w && !sign; k++) {
				step.clear();
				memset(vis, 0, sizeof(vis));
				if (dfs(j, k, 0)) sign = 1;
			}
		}
		if (sign) cout << step << endl;
		else cout << "impossible" << endl;
		cout << endl;
	}
}

