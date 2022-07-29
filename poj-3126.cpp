/*
问题描述：
内阁部长们对安全局局长发来的信息感到非常沮丧，他说他们都必须改变办公室的四位数房间号。
——时不时地改变这种事情，使敌人蒙在鼓里，这是一个安全问题。
- 但是看，我选择我的号码1033是有充分理由的。我是总理，你知道的！
—— 我知道，所以你的新号码8179也是一个素数。您只需要在办公室门上的四个旧数字上粘贴四个新数字即可。
—不，没那么简单。假设我将第一个数字更改为8，那么该数字将读取8033，这不是素数！
——我明白了，作为总理，你无法忍受在门上有一个非总理号码，哪怕只有几秒钟。
— 正确！因此，我必须发明一个方案，通过素数路径从1033到8179，其中只有一个数字从一个素数更改为下一个素数。

现在，一直在窃听的财政部长进行了干预。
— 请不要有不必要的开支！我碰巧知道一个数字的价格是一磅。
- 嗯，在这种情况下，我需要一个计算机程序来最小化成本。你不认识一些非常便宜的软件大师，对吧？
——事实上，我做到了。你看，有一个编程比赛正在进行中...帮助总理在任何两个给定的四位数总理之间找到最便宜的总理路径！
当然，第一个数字必须是非零的。这是上述情况下的解决方案。
1033
1733
3733
3739
3779
8779
8179
该解决方案的成本为6英镑。请注意，在步骤 2 中粘贴过来的数字 1 不能在最后一步中重复使用 - 必须购买新的 1。
*
求解思路：
（1）首先一个简单的预处理，判断哪些是素数，并保存到prime数组中 
（2）将step数组全部初始化为0， 把每组数据的初始数表示为step1 
（3）利用队列的方式进行bfs搜素 ，d数组表示数的每一位 
（4）用ori表示当前的数字，只要当前数字为b就停止搜索 
（5）每次搜索先从第一位开始，保证换后的数仍为一个素数 ，再改变后三位保证每次都是素数，并不断地出队 
	   
*
提交状态：AC
*
AC结果：204K	16MS

*
出错次数：
5、6次
错误结果：
刚开始对回溯算法掌握的不牢固，对一些C++自带函数认识不全，不懂得使用方法。 
测试数据的范围不准确认知，对数据的范围和特殊值把握不准



*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<queue>
using namespace std;
const int SIZE = 10000;
bool prime[SIZE];
int step[SIZE];
int base[4] = {1,10,100,1000};
int main()
{
        for(int i = 0; i < SIZE; i++)prime[i] = true;
        
        for(int i = 2; i < SIZE; i++){
                if(prime[i]){
                             for(int j = 2; i*j < SIZE; j++)
                                     prime[i*j] = false;             
                }        
        }
        
        int t,a,b,d[4];
        scanf("%d",&t);
        while(t--){
                   scanf("%d %d",&a,&b);
                   fill(step,step+SIZE,0);
                   queue<int>path;
                   path.push(a);
                   step[a] = 1;
                   while(!path.empty()){
                         int ori = path.front();
                         if(ori == b)break;
                         path.pop();
                         d[0] = ori%10;  d[1] = ori%100/10;
                         d[2] = ori%1000/100;  d[3] = ori/1000;
                         int newnum;
                         for(int i = 0; i < 10; i ++){                                                   
                                 newnum = ori - d[3]*1000 + i*1000;
                                 if(i != 0 && prime[newnum] && !step[newnum]){
                                      step[newnum] = step[ori] + 1;
                                      path.push(newnum);               
                                 } 
                                 for(int k = 0; k < 3; k++){
                                         newnum = ori - d[k]*base[k] + i*base[k];
                                         if(prime[newnum] && !step[newnum]){
                                              step[newnum] = step[ori] + 1;
                                              path.push(newnum);               
                                         }                               
                                 }  
                         }                     
                   }     
                   printf("%d\n",step[b]-1);
        }        
        return 0;
}
