/*
��������������� DNA �ַ������У��������ĸ���ĸ A��C��G �� T �����У����б�Ŀ��
���ǣ���ϣ�������ǽ��б�Ŀ�����ǰ���ĸ˳�򣬶��ǰ�������˳�򣬴ӡ�������ࡱ�����������١���
�����ַ����ĳ��ȶ���ͬ�� 
���˼·�� 
��1�����ȶ�ȡÿ�����У�DNA���У��ĳ���n��DNA���еĸ���m 
��2��Ȼ�����ÿ�����еĿɷ�ת���򣬼���Ŀ����ָ�Ķ��������浽һ��temp�����С�
��3�����Ƹ����飬�Ա���������������ʾ�ɷ�ת�����������С��������
��4��������õ����а��ɴ�С��˳����� 
*/

#include<iostream>
using namespace std;

int getnum(int n,int m, char litter[100][50],int temp[50]){
    for(int p=0;p<m;p++)
       for(int k=0;k<n;k++)
            for(int l=k+1;l<n;l++)
                while(litter[p][k]>litter[p][l])
                {
                    temp[p]++;
                    break;
                }
  	return litter[100][50],temp[50]; 
} 
int sort(int n,int m,int temp[50]){
	int t = 0;
    for(int k=0;k<m;k++)
        for(int l=k+1;l<m;l++)
            if(temp[k]>temp[l])
            {
                t = temp[l];
                temp[l] = temp[k];
                temp[k] = t;
            }
	return temp[50];
} 
int main()
{
    char litter[100][50] = {};
    int n = 0,m = 0;
    int temp[50] = {0};
    cin>>n>>m;

    for(int k=0;k<m;k++)
    {
        for(int l=0;l<n;l++)
        {
            cin>>litter[k][l];
        }
    }
    getnum(n,m,litter,temp);
	int number[50] = {0};
	for(int k=0;k<m;k++)
    {
        number[k] = temp[k];
    }
    sort(n,m,temp);
    for(int k=0;k<m;k++)
        for(int l=0;l<m;l++)
            if(temp[k]==number[l]){
			
                for(int p=0;p<n;p++)
                {
                    cout<<litter[l][p];
                }
                cout<<endl;
            }
    return 0;
}
