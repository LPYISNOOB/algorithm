#include<stdio.h>


int main(){
	int num, n, m, k;
	long long num1 = 0;
	scanf("%d",&num);
	for(int j = 0;j<num;j++){
	
	scanf("%d %d %d",&n, &m, &k);
	int w[1000000] = {0};
	int e[1000000] = {0};
	for(int i = 0;i < k;i++){
		scanf("%d %d",&w[i],&e[i]);
	}
	for(int i = 0;i < k;i++)
		for(int j = 1;j < k-i;j++){
			if((e[i] > e[j] && w[i] < w[j]) or (e[i] < e[j] && w[i] > w[j]))
			num1++;
		}
	printf("Test case %d: %d\n",num,num1);

}
return 0;
}

