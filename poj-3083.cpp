/*
问题描述：玉米田迷宫是一种受欢迎的万圣节美食。参观者将看到入口，并且必须漫步在迷宫中，
面对僵尸，挥舞着电锯的精神病患者，嬉皮士和其他恐怖人物，以寻找出口。

一种流行的迷宫行走策略可以保证游客最终会找到出口。只需选择右边或左边的墙，然后跟随它。
当然，不能保证哪种策略（左或右）会更好，而且所采取的路径很少是最有效的。（它也不适用于出口不在边缘的迷宫;这些问题中不表示这些类型的迷宫。

作为即将被改造成迷宫的玉米地的主人，您希望拥有一个计算机程序，
该程序可以确定左右路径以及最短路径，以便您可以找出哪种布局最有可能混淆访问者。

*
求解思路：
（1）存取数组的长和宽，用map数组存储地图 
（2）wall函数表示从左边和右边走的走的长度，当one—hand为1时表示右边，为-1时表示左边 ，利用bfs求解出最短距离 
（3）getdir函数用于获取初始位置 ，返回值0、1、2、3表示四条边的起始位置，用于确定后续的左右 
（4）wall函数中 只要当前坐标不为出口就会一直移动，通过计算dir的值来确定移动的方向，以及计算移动后的位置 
（5）bfs函数则利用队列实现广度搜索 
	   
*
提交状态：AC
*
AC结果：
220K	16MS
*
出错次数：
5、6次
错误结果：
方向难以表示 ，迷宫的入口不同，左右方向不同。 


*/
#include <stdio.h>
#include <queue>
using namespace std;

char map[42][42] = {};

struct node {
    int x;
    int y;
    int step;
};

int move_x[4] = { 1, 0, -1, 0 }; 
int move_y[4] = { 0, -1, 0, 1 };

int getdir(int w, int h, int &startx, int &starty) {
    for(int i = 2; i <= h-1; i++) {
        if(map[i][1] == 'S') {
            startx = i;
            starty = 1;
            return 0;
        }
        if(map[i][w] == 'S') {
            startx = i;
            starty = w;
            return 2;
        }
    }
    for(int i = 2; i <= w-1; i++) {
        if(map[1][i] == 'S') {
            startx = 1;
            starty = i;
            return 1;
        }
        if(map[h][i] == 'S') {
            startx = h;
            starty = i;
            return 3;
        }
    }
}

int bfs(int w, int h) {
    bool visit[42][42] = {};
    int startx, starty;
    getdir(w, h, startx, starty);
    queue<node> q;
    visit[startx][starty] = true;
    node first;
    first.x = startx;
    first.y = starty;
    first.step = 1;
    q.push(first);
    while(!q.empty()) {
        first = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) { 
            int nowx = first.x + move_x[i];
            int nowy = first.y + move_y[i];
            if(map[nowx][nowy] == 'E') {
                return first.step + 1;
            }
            if(map[nowx][nowy] != '#' && !visit[nowx][nowy]) {
                visit[nowx][nowy] = true;
                node tmp;
                tmp.x = nowx;
                tmp.y = nowy;
                tmp.step = first.step+1;
                q.push(tmp);
            }
        }
    }
}

int wall(int one_hand, int w, int h) {
    int nowx, nowy;
    int dir = getdir(w, h, nowx, nowy);
    int res = 1;
    while(map[nowx][nowy] != 'E') {
        dir = (dir + 4 + one_hand) % 4;
        while(map[nowx+move_x[dir]][nowy+move_y[dir]] == '#') {
            dir = (dir + 4 + one_hand*(-1)) % 4;
        }
        nowx += move_x[dir];
        nowy += move_y[dir];
        res++;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int w, h;
        scanf("%d %d", &w, &h);
        for(int i = 1; i <= h; i++) {
            scanf("%s", &map[i][1]);
        }
        for(int i = 0; i< h+2; i++) {
            map[i][0] = map[i][w+1] = '#';
        }
        for(int i = 0; i < w+2; i++) {
            map[0][i] = map[h+1][i] = '#';
        }
        
        printf("%d %d %d\n", wall(-1, w, h), wall(1, w, h), bfs(w, h));
    }
}
