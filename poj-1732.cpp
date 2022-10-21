/*
问题描述：
有 N (N <= 50000)个单词（每个单词长度不超过50），问组成长度不超过100的目标串最少要用多少个单词。
*
求解思路：dp
（1） word[MAXN][MAXW]数组用于存储单词， dp[i]数组表示符合长度为i时，所用的单词数 
buf[i][j]数组用于存储单词字母转化后的数组，其中a对应0，b对应1，依此类推 
path数组用于保存打印所用到的单词的路径 
（2）状态转移方程为	dp[i + wLen - 1] = min(dp[i + wLen - 1], dp[i - 1] + 1)	   
（3）从电话串的开头开始，那每个单词的长度n和当前电话串的开头比较，若前 n符合就将其加入路径。 
（4）输出所用到的单词时，会先从最后一位开始，随后每次减去该单词的长度，就找到上一个单词末尾的位置，以此类推
*
提交状态：AC
*
AC结果：
3132K	110MS
*
出错次数：
2次
错误结果：
编译错误，超时 

*/
#include <cstdio>
#include <cstring>
#include <algorithm>
 
const int MAXN = 50000 + 10;
const int MAXW = 50 + 10;
const int MAXT = 100 + 10;
const int INF = 0x3f3f3f3f;
const char *h = "22233344115566070778889990";
 
int N;
char s[MAXT];
char word[MAXN][MAXW], buf[MAXN][MAXW];
int dp[MAXT];
int path[MAXT];
bool first;
 
void Read()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%s", word[i]);
    }
}
 
void Init()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; word[i][j] != '\0'; ++j)
        {
            buf[i][j] = h[word[i][j] - 'a'];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    first = true;
}
 
void Dp()
{
    int len = strlen(s);
 
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int wLen = strlen(buf[j]); 
 
            if (i + wLen - 1 < len && strncmp(&s[i], buf[j], wLen) == 0)
            {
                if (i == 0)
                {
                    dp[i + wLen - 1] = 1;
                    path[i + wLen - 1] = j;
                }
                else if (dp[i - 1] + 1 < dp[i + wLen - 1])
                {
                    dp[i + wLen - 1] = dp[i - 1] + 1;
                    path[i + wLen - 1] = j;
                }
            }
        }
    }
}

void DfsPrint(int pos)
{
    if (pos == -1) return;
    DfsPrint(pos - strlen(word[path[pos]]));
    if (first)
    {
        first = false;
    }
    else
    {
        printf(" ");
    }
    printf("%s", word[path[pos]]);
}
 
void Output()
{
    int len = strlen(s);
 
    if (dp[len - 1] == INF)
    {
        puts("No solution.");
    }
    else
    {
        DfsPrint(len - 1);
        puts("");
    }
}
 
int main()
{
    while (scanf("%s", s) == 1)
    {
        Read();
        Init();
        Dp();
        Output();
    }
 
    return 0;
}
