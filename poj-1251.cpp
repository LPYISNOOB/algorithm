/*
����������
�ȴ��������е���Ԫ����һ�����⡣����ǰ���������Ԯ���ʽ����˴�ׯ֮��Ķ����·�ϡ�
����������س�Խ�˵�·����˴��͵�·����ά���ɱ�̫�ߡ����ϻ������ѡ��ֹͣά��һЩ��·��
���Ϸ��ĵ�ͼ��ʾ��Ŀǰʹ�õ����е�·�Լ�ÿ��ά����Щ��·�ĳɱ����� aacms Ϊ��λ����
��Ȼ����Ҫ��һЩ������ά����·�ϵ����д�ׯ֮�䵽���ʹ·�߲�����ǰ��ô�̡�
��ϯ��������߳������»ᣬ����ÿ�¿��Ի��ѵ���С�����ά���������д�ׯ�ĵ�·��
������ĵ�ͼ�У���Щ��ׯ�����ΪA��I���ұߵĵ�ͼ��ʾ�˿���ά���ɱ���͵ĵ�·��ÿ��ά��216 aacms��
��������Ǳ�дһ�������������Щ���⡣
*
���˼·����С������+prim�㷨 
��1���������ڽӾ���ķ�ʽ�洢��ͼ��road��i����j����ֵ��ʾ��i�㵽j��ľ��롣position(char s)��������ȷ����ĸ����ĸ���е�λ�� �� 
��2�� �ӵ�һ���������ѡȡ���������һ���㣬����С�ߵ�һ���㣬����ѡȡ���ĵ㣬����ǣ������ڷ��� ��������̵ı��ۼ� �� 
��3�� ������չ ���ظ� ��2���Ĳ��裬ֱ�����е㶼�߹�����̵ıߵ��ۼӾ��ǻ��ѵġ� 
*
�ύ״̬��AC
*
AC�����
284K	16MS
*
���������
1��
��������
*/

#include<iostream>
#include<cstring>
using namespace std;
int road[100][100];
int dist[100];
bool visit[100];
char dic[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int position(char s)
{
	int i;
	for(i = 0;;i++)
		if(dic[i] == s)
		return i; 
 } 
int main()
{
	int s,e,n,m,dis,sum;
	char name,node;
	memset(visit,0,sizeof(visit));
	for(int i = 1;i <= 100;i++){
		for(int j = 1;j <= 100;j++)
			road[i][j] = 10000;
			road[i][i] = 0;
	}
	while(cin>>n && n != 0)
	{
		for(int j = 1;j < n;j++)
		{
			cin>>name>>m;
			s=position(name);
			while(m--){
				cin>>node>>dis;
				e=position(node);
				road[e][s]=dis;
				road[s][e]=dis;		
			}
		}
		for(int i = 1;i < n;i++)
		dist[i]=road[1][i];
        visit[1]=1;
        sum = 0;
		for(int i = 1;i < n;i++)
		{
			int max = 10000;
			int rec = -1;
			for(int j = 1;j <= n;j++)
				if(!visit[j]&&dist[j]<max) 
				{
					max = dist[j];
					rec = j;
				}
			sum+=dist[rec];
			visit[rec] = 1;
			for(int j = 1;j <= n;j++)
				if(!visit[j]&&road[rec][j] < dist[j])
					dist[j] = road[rec][j];	
		}
		cout<<sum<<endl;
	}
	return 1;
}









