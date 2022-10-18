/*
问题描述：
一些主要城市有树形的地铁系统，即在任何一对车站之间，有一种也是只有一种地铁方式。
此外，这些城市中的大多数都有一个独特的中央车站。想象一下，你是这些城市之一的游客，
你想探索所有的地铁系统。你从中央车站开始，随机选择一条地铁线，然后跳上地铁车厢。
每次到达车站时，您都会选择一条尚未行驶的地铁线路。如果当前车站没有剩余的探索空间，
您可以乘坐您最初到达车站的地铁线路，直到您最终沿着所有线路行驶两次，每个方向一次。
此时，您将返回中央车站。之后，你对探索顺序的记忆就是你在任何给定时间是离中央车站更远还是朝向中央车站，
即你可以将你的旅行编码为二进制字符串，其中0编码采取地铁线，使你离中央车站更远，1编码让你离中央车站更近一个车站。
输入的第一行是单个正整数n，告诉要遵循的测试场景的数量。
每个测试场景由两行组成，每行都包含长度最多为 3000 的字符“0”和“1”字符串，
两者都描述了地铁树系统的正确探索之旅。
*
求解思路：同构树的判断 
（1）利用solve(int l,int r)函数将两串01编码用树的形式表现
（2）并将每条路径节点保存在vector中， 当cnt==0时即为 重回该节点，然后递归 
（3）将vector中的元素重新排序，构造新的表示方法，并得到新的编码串
（4）比较两棵树的新编码串。 
*
提交状态：AC
*
AC结果：
596K	360MS
*
出错次数：
1、2 次 
错误结果：
超时 

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#define next ne
using namespace std;
typedef long long ll;
int INF=1e9+7;
int n,ans,maxlen;
char s[10010];

string solve(int l,int r)
{
    vector<string> v;
    int cnt=0,p=l;
    for(int i=l;i<=r;i++)
    {
        if(s[i]=='0')
            cnt++;
        else
            cnt--;
        if(cnt==0)
        {
            v.push_back(solve(p+1,i-1));    //当发现重新回到当前节点就递归进入这个节点
            p=i+1;
        }
    }
    sort(v.begin(),v.end());    //将节点按个数排序
    string re="0";
    for(int i=0;i<(int)v.size();i++)    //构造新的表示方法
        re=re+v[i];
    return re+"1";
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int l;
        scanf(" %s",s);
        l=strlen(s);
        string a=solve(0,l-1);
        scanf(" %s",s);
        l=strlen(s);
        string b=solve(0,l-1);
        if(a==b)
            printf("same\n");
        else
            printf("different\n");
    }
}
