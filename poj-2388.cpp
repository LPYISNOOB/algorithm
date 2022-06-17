///*
//问题描述：给定奇数奶牛 N（1 <= N < 10，000）及其产奶量 （1..1，000，000），
//找到给定的中位数牛奶量，使至少一半的奶牛给予相同量或更多，
//至少一半给予相同或更少的牛奶。 
//求解思路：
//（1）读取奶牛的数量奇数n，并读取奶量数组arr；
//（2）将arr数组排序； 
//（3）输出arr数组的中位数；  
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
