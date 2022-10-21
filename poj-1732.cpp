/*
����������
�� N (N <= 50000)�����ʣ�ÿ�����ʳ��Ȳ�����50��������ɳ��Ȳ�����100��Ŀ�괮����Ҫ�ö��ٸ����ʡ�
*
���˼·��dp
��1�� word[MAXN][MAXW]�������ڴ洢���ʣ� dp[i]�����ʾ���ϳ���Ϊiʱ�����õĵ����� 
buf[i][j]�������ڴ洢������ĸת��������飬����a��Ӧ0��b��Ӧ1���������� 
path�������ڱ����ӡ���õ��ĵ��ʵ�·�� 
��2��״̬ת�Ʒ���Ϊ	dp[i + wLen - 1] = min(dp[i + wLen - 1], dp[i - 1] + 1)	   
��3���ӵ绰���Ŀ�ͷ��ʼ����ÿ�����ʵĳ���n�͵�ǰ�绰���Ŀ�ͷ�Ƚϣ���ǰ n���Ͼͽ������·���� 
��4��������õ��ĵ���ʱ�����ȴ����һλ��ʼ�����ÿ�μ�ȥ�õ��ʵĳ��ȣ����ҵ���һ������ĩβ��λ�ã��Դ�����
*
�ύ״̬��AC
*
AC�����
3132K	110MS
*
���������
2��
��������
������󣬳�ʱ 

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
