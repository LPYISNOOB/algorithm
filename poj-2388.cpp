///*
//��������������������ţ N��1 <= N < 10��000����������� ��1..1��000��000����
//�ҵ���������λ��ţ������ʹ����һ�����ţ������ͬ������࣬
//����һ�������ͬ����ٵ�ţ�̡� 
//���˼·��
//��1����ȡ��ţ����������n������ȡ��������arr��
//��2����arr�������� 
//��3�����arr�������λ����  
#include <iostream>
using namespace std;
int arr[10000000];
int main()
{
    int k,i,j,min,t;
    cin>>k;
    for(i=1; i<=k; i++)
        cin>>arr[i];
    for(i=1; i<=k-1; i++)
    {
        min=i;
        for(j=i+1; j<=k; j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        if(min!=i)
        {
            t=arr[i];
            arr[i]=arr[min];
            arr[min]=t;
        }
    }
    cout<<arr[(k+1)/2]<<endl;
    return 0;
}
