/*
问题描述：
乔治拿起相同长度的棍子，随机切割它们，直到所有零件最多变成50个单位长。
现在他想把棍子恢复到原来的状态，但是他忘记了他原来的棍子有多少根，以及它们原来的长度。
请帮助他并设计一个程序，计算这些棍子的最小原始长度。所有以单位表示的长度都是大于零的整数。
*
求解思路：
（1）创建数组S[]表示截取后的各段长度，bool型数组used[]，用来表示 
（2）将s数组由大到小排序，节省后续运行时间 
（3）可能的长度一定大于s[0]，所以从S[0]开始逐渐加一寻找正确的长度 
（4）通过判断棍子的可能长度能否被所有棍子长度总和整除来判断是否为可能的长度，并为used数组赋值 
（5）同过深度搜索来判断该可能的长度是否正确 
    通过迭代和回溯不断更新used数组，并判断是否可行。 
	   
*
提交状态：AC
*
AC结果：
220K	16MS
*
出错次数：
十余次
错误结果：
刚开始对回溯算法掌握的不牢固，对一些C++自带函数认识不全，不懂得使用方法。 
测试数据的范围不准确认知，对数据的范围和特殊值把握不准



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






