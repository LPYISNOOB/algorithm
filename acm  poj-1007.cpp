/*
问题描述：负责对 DNA 字符串序列（仅包含四个字母 A、C、G 和 T 的序列）进行编目。
但是，您希望对它们进行编目，不是按字母顺序，而是按“排序”顺序，从“排序最多”到“排序最少”。
所有字符串的长度都相同。 
求解思路： 
（1）首先读取每个序列（DNA序列）的长度n和DNA序列的个数m 
（2）然后计算每个序列的可翻转次序，即题目中所指的度量，保存到一个temp数组中。
（3）复制该数组，以便后续的输出，将表示可翻转次序的数组由小到大排序
（4）将排序好的序列按由大到小的顺序输出 
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
