/*
����������
��n��ʫ��ÿ�ж��������ɡ���n��ʫ���ڵ������������ 
*
���˼·���ڶ���Stirling��
��1���ڶ���Stirling���ǰ�n��Ԫ�ط���k���ȼ���ķ�����Ŀ(ÿ���ȼ��඼����Ϊ��)
(2) ע�⵽�����'����'>='������',���԰�'����'����Ϊn��Ԫ��,'������'����Ϊk���ȼ���. 
(3)����Ϊ����n�з���k�������ɡ��еķ�����( ����:1=< k <=n )��
(4)״̬ת�Ʒ���ΪF[ i,  j ]  =  F[ i-1,  j-1 ]  +  F[ i-1,  j ]  *  j 
*
�ύ״̬��AC
*
AC�����
280K	0MS
*
���������
1��
��������

*/
#include<iostream>
#include<cstdio>
using namespace std;
 
// ����
int n; // ����
double F[101][101]; // F[i][j]:��ʾ��i����װ��j�������еķ�����(ÿ�����Ӷ��ǿ�)
 
void DP()
{
	// init
	for( int j = 1; j <= 100; ++ j )
		F[1][j] = 0;
	for( int i = 1; i <= 100; ++ i )
		F[i][1] = 1;
 
	// dp
	for( int i = 2; i <= 100; ++ i )
		for( int j = 2; j <= i; ++ j )
			F[i][j] = F[i-1][j-1] + F[i-1][j]*j;
}
 
int main()
{
	DP();
	while( cin >> n && n )
	{
		double res = 0;
		for( int i = 1; i <= n; ++ i )
			res += F[n][i];
		printf( "%d %.0f\n", n, res );
	}
	return 0;
}
