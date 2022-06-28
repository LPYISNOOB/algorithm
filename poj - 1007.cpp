
/*
问题描述：负责对 DNA 字符串序列（仅包含四个字母 A、C、G 和 T 的序列）进行编目。
但是，您希望对它们进行编目，不是按字母顺序，而是按“排序”顺序，从“排序最多”到“排序最少”。
所有字符串的长度都相同。 
*
提交状态：AC
*
AC结果：164K	0MS 
*
求解思路： 
（1）首先读取每个序列（DNA序列）的长度n和DNA序列的个数m 
（2）然后计算每个序列的可翻转次序，即题目中所指的度量。 
（3）复制该数组，以便后续的输出，将表示可翻转次序的数组由小到大排序
（4）将排序好的序列按由大到小的顺序输出 
*
出错次数：
十余次
* 
对poj使用方式的不了解；
对答案格式的错误认识；
刚开始对题目的错误解读： 
*/
#include<iostream>
#include<algorithm>

using namespace std;
struct DNAsort{
	int num;
	char *line;
}a[101];
int bubble_sort(char a[],int n);
bool cmp(DNAsort a, DNAsort b);

int main(){
	int n, m, i, j;
	char DNA[101][52];
	scanf("%d %d\n", &n, &m);
	for(i = 0;i < m;i++){
		gets(DNA[i]);
		a[i].line = DNA[i];
		a[i].num = bubble_sort(DNA[i],n);
	}
	sort(a,a + m,cmp);
	for(i = 0;i < m;i++){
		for(j = 0;j < n;j++){
			printf("%c", a[i].line[j]);
		}
		 printf("\n");
	}
	return 0;

}

bool cmp(DNAsort a, DNAsort b) {
    return a.num < b.num;
}

int bubble_sort(char a[], int n) {
    int i, j, num = 0;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] > a[j]) num++;
    return num;
}
