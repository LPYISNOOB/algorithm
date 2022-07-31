/*
����������
�㱻����3D�������Ҫ�ҵ����ĳ�·�������ɵ�λ��������ɣ���Щ������������Ҳ���ܲ������ʯ��
�򱱡����ϡ��򶫡����������ϻ������ƶ�һ����Ԫ��Ҫһ���ӡ��㲻�ܶԽ����ƶ����Թ����滷���ż�̵���ʯ��
�п�������������ǣ���Ҫ�೤ʱ�䣿
�����������³���ɡ�ÿ��������������һ�п�ʼ�����а�����������L��R��C����С������Ϊ30����
L����ɵ��εĹؿ�������
R �� C �����ÿ������ƻ���������������
Ȼ�󣬽���ѭR�е�L�飬ÿ�������C�ַ���ÿ����ɫ�������ε�һ��ϸ����
������ʯ�ĵ�Ԫ���ɡ�#����ʾ���յ�Ԫ���ɡ�.����ʾ��������ʼλ���ɡ�S����ʾ��
�˳�λ������ĸ��E����ʾ��ÿ���������һ�����С������� L��R �� C ��������˽ӡ�
*
���˼·����ά�Ĺ������ 
��1�����ȶ�ȡ��ͼ��������mapp[i][j][k]������ 
��2���ҵ���ʼλ�ã���������x/y/z���� ��������ʱ��step����Ϊ0 
��3����ʼ���������ö��н���bfs���� 
��4��ÿ�ε��ƶ���dir�����ʾ�������ַ���ǰ���������� 
��5��һֱ�������������ı�ʾE 
*
�ύ״̬��AC
*
AC�����
400K	32MS
*
���������
4��5��
��������
�Ի����㷨���յĲ��ι̣���һЩC++�Դ�������ʶ��ȫ��������ʹ�÷����� 
�������ݵķ�Χ��׼ȷ��֪�������ݵķ�Χ������ֵ���ղ�׼

*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
char mapp[35][35][35];
struct node{
    int x,y,z,step;
}e,rr;
int dir[6][3]={
0,1,0,
0,-1,0,
0,0,1,
0,0,-1,
1,0,0,
-1,0,0
};
int vis[35][35][35];
queue<node>qu;
int main(){
    int l,r,c,i,j,k;
    while(~scanf("%d%d%d",&l,&r,&c),l+r+c){
        memset(vis,0,sizeof(vis));
        while(!qu.empty())qu.pop();
        for(i=0;i<l;i++){
            getchar();
            for(j=0;j<r;j++){
                for(k=0;k<c;k++){
                    scanf("%c",&mapp[i][j][k]);
                    if(mapp[i][j][k]=='S'){
                        e.x=i;
                        e.y=j;
                        e.z=k;
                        e.step=0;
                        qu.push(e);
                    }
                }
                getchar();
            }
        }
        while(!qu.empty()){
            e=qu.front();
            qu.pop();
            rr.step=e.step+1;
            for(i=0;i<6;i++){
                rr.x=e.x+dir[i][0];
                rr.y=e.y+dir[i][1];
                rr.z=e.z+dir[i][2];
                if(0<=rr.x&&rr.x<l&&0<=rr.y&&rr.y<r&&0<=rr.z&&rr.z<c&&vis[rr.x][rr.y][rr.z]==0&&mapp[rr.x][rr.y][rr.z]!='#'){
                    if(mapp[rr.x][rr.y][rr.z]=='E'){
                        printf("Escaped in %d minute(s).\n",rr.step);
                        goto l1;
                    }
                    qu.push(rr);
                    vis[rr.x][rr.y][rr.z]=1;
                }
            }
        }
        printf("Trapped!\n");
        l1:;
    }
    return 0;
}
