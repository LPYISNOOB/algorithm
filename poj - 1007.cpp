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
