/*
问题描述：
你被困在3D地牢里，需要找到最快的出路！地牢由单位立方体组成，这些立方体可能填充也可能不填充岩石。
向北、向南、向东、向西、向上或向下移动一个单元需要一分钟。你不能对角线移动，迷宫四面环抱着坚固的岩石。
有可能逃脱吗？如果是，需要多长时间？
输入由许多地下城组成。每个地牢描述都以一行开始，其中包含三个整数L，R和C（大小均限制为30）。
L是组成地牢的关卡数量。
R 和 C 是组成每个级别计划的行数和列数。
然后，将遵循R行的L块，每个块包含C字符。每个角色描述地牢的一个细胞。
充满岩石的单元格由“#”表示，空单元格由“.”表示。您的起始位置由“S”表示，
退出位置由字母“E”表示。每个级别后都有一个空行。输入由 L、R 和 C 的三个零端接。
*
求解思路：多维的广度搜索 
（1）首先读取地图，保存在mapp[i][j][k]数组中 
（2）找到起始位置，保存它的x/y/z坐标 ，并将此时的step设置为0 
（3）开始搜索，利用队列进行bfs搜索 
（4）每次的移动用dir数组表示，有六种方向即前后左右上下 
（5）一直到搜索到结束的表示E 
*
提交状态：AC
*
AC结果：
400K	32MS
*
出错次数：
4、5次
错误结果：
对回溯算法掌握的不牢固，对一些C++自带函数认识不全，不懂得使用方法。 
测试数据的范围不准确认知，对数据的范围和特殊值把握不准

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
