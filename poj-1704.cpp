/*
问题描述：
乔治亚和鲍勃决定玩一个自己发明的游戏。他们在纸上画一排网格，
从左到右按1，2，3，...编号网格，并将N个棋手放在不同的网格上，如下图所示，例如：
格鲁吉亚和鲍勃依次移动棋手。每次玩家都会选择一个棋手，
并将其向左移动，而不会越过任何其他棋手或越过左边缘。玩家可以自由选择棋手移动的步数，
约束下棋手必须至少移动一步，一个网格最多可以包含一个棋手。无法移动的玩家将输掉游戏。
佐治亚州自“第一夫人”以来一直都是第一位的。假设乔治亚和鲍勃都在游戏中尽了最大的努力，
也就是说，如果他们中的一个人知道赢得比赛的方法，他或她将能够做到这一点。
鉴于n名棋手的初始位置，你能预测谁将最终赢得比赛吗？
*
求解思路：阶梯博弈 （进阶的nim博弈）  
（1）把序列按从小到大的顺序排列 
（2）每两个棋子：看作一个石堆，如上图中1和3看作一个石堆，
6和7看作一个石堆，如果棋子个数为奇数个，那么首个棋子与网格的边界作为一个石堆求序列差的异或和，
棋子之间的空格数量：看作石堆中的石子数量
任意一个棋子向左移动任意步数：看作从任意一个石堆中取出任意数量石子
如果为0那么bob赢，如果不为0那么georgia赢。 
*
提交状态：AC
*
AC结果：
180K	16MS
*
出错次数：
1次
错误结果：
编译错误 
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1000;
int a[N];

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);

        if(n & 1) a[n++] = 0;     /* n为奇数时，增加0 */
        sort(a, a + n);
        int ans = 0;
        for(int i = 0; i < n - 1; i += 2) 
			ans ^= a[i + 1] - a[i] - 1;
        puts(ans ? "Georgia will win" : "Bob will win");
    }

    return 0;
}

