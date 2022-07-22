/*
����������
��һ��������״�����̣���״�����ǲ�����ģ�����ڷ����ӣ�����û������
Ҫ��ڷ�ʱ������������Ӳ��ܷ��������е�ͬһ�л���ͬһ�У�
���������ڸ�����״�ʹ�С�����̣��ڷ�k�����ӵ����п��еİڷŷ���C��
*
���˼·��row��ʾ�У�col��ʾ�У������̽���������� 
��1����ÿ�����̶�ȡ��chess������ 
��2����ÿ�����̽���dfs���� 
��3��ֻ����chess[row][i] == '#'ʱ����ѡ��Ż򲻷� ��ÿһ�ж���������ѡ�� 
��4������������nʱdfs���� ��k����Ҫ�ŵ�������ʱ���� 
	   
*
�ύ״̬��AC
*
AC�����
220K	141MS
*
���������
3��
��������
�տ�ʼ�Ի����㷨���յĲ��ι̣���һЩC++�Դ�������ʶ��ȫ��������ʹ�÷����� 
�������ݵķ�Χ��׼ȷ��֪�������ݵķ�Χ������ֵ���ղ�׼



*/
#include <iostream>
#include <cstring>
using namespace std;

const int ROW = 10;
const int COL = 10;

int book[COL];
char chess[ROW][COL];
int step, n;
long long  sum;


void DFS(char chess[][COL], int row,int k) {
	if (row > n)
		return;
	if (k == step) {
		sum++;
		return;
	}
		
	for (int j = 1; j <= 2; j++) {
		if (j == 1)
			DFS(chess, row + 1, k);
		if (j == 2) {
			for (int i = 0; i < n; i++) {
				if (book[i] == 0 && chess[row][i] == '#') {
					book[i] = 1;
					DFS(chess, row + 1, k + 1);
					book[i] = 0;
				}
			}
		}
	}
}


int main() {
	while (cin >> n >> step) {
		sum = 0;
		cin.get();
		if (n == -1 && step == -1)
			break;
		for (int i = 0; i < n; i++)
			cin >> chess[i];
	
			DFS(chess, 0, 0);
		


		cout << sum << endl;
	}
}
