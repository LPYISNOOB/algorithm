/*
����������
����������ͬ���ȵĹ��ӣ�����и����ǣ�ֱ��������������50����λ����
��������ѹ��ӻָ���ԭ����״̬����������������ԭ���Ĺ����ж��ٸ����Լ�����ԭ���ĳ��ȡ�
������������һ�����򣬼�����Щ���ӵ���Сԭʼ���ȡ������Ե�λ��ʾ�ĳ��ȶ��Ǵ������������
*
���˼·��
��1����������S[]��ʾ��ȡ��ĸ��γ��ȣ�bool������used[]��������ʾ 
��2����s�����ɴ�С���򣬽�ʡ��������ʱ�� 
��3�����ܵĳ���һ������s[0]�����Դ�S[0]��ʼ�𽥼�һѰ����ȷ�ĳ��� 
��4��ͨ���жϹ��ӵĿ��ܳ����ܷ����й��ӳ����ܺ��������ж��Ƿ�Ϊ���ܵĳ��ȣ���Ϊused���鸳ֵ 
��5��ͬ������������жϸÿ��ܵĳ����Ƿ���ȷ 
    ͨ�������ͻ��ݲ��ϸ���used���飬���ж��Ƿ���С� 
	   
*
�ύ״̬��AC
*
AC�����
220K	16MS
*
���������
ʮ���
��������
�տ�ʼ�Ի����㷨���յĲ��ι̣���һЩC++�Դ�������ʶ��ȫ��������ʹ�÷����� 
�������ݵķ�Χ��׼ȷ��֪�������ݵķ�Χ������ֵ���ղ�׼



*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
int s[65],sum=0,Maylen,num,n;
bool used[65];
int cmp(const void* a,const void* b)
{
    return *(int*)b-*(int*)a;
}
bool dfs(int sticks,int curlen,int pos)
{
    int i;
    if(sticks==num)
        return true;
    for(i=pos+1;i<n;i++)
    {
        if(used[i])
            continue;
        if(curlen+s[i]==Maylen)
        {
            used[i]=true;
            if(dfs(sticks+1,0,-1))
                return true;
            used[i]=false;
            return false;
        }
        else if(curlen+s[i]<Maylen)
        {
            used[i]=true;
            if(dfs(sticks,curlen+s[i],i))
                return true;
            used[i]=false;
            if(!curlen)
                return false;
            while(s[i]==s[i+1])
                i++;
        }
    }
    return false;
}
using namespace std;
int main()
{
    while(scanf("%d",&n)==1)
    {
        if(!n)
            break;
        sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            sum+=s[i];
        }
        qsort(s,n,sizeof(int),cmp);
        for(Maylen=s[0];Maylen<=sum;Maylen++)
        {
            if(sum%Maylen)
                continue;
            else
                num=sum/Maylen;
            memset(used,false,sizeof(used));
            if(dfs(1,0,-1))
            {
                cout<<Maylen<<endl;
                break;
            }
        }
    }
    return 0;
}






