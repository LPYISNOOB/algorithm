/*
�����������������Թ���һ���ܻ�ӭ����ʥ����ʳ���ι��߽�������ڣ����ұ����������Թ��У�
��Խ�ʬ�������ŵ��ľ��񲡻��ߣ���Ƥʿ�������ֲ������Ѱ�ҳ��ڡ�

һ�����е��Թ����߲��Կ��Ա�֤�ο����ջ��ҵ����ڡ�ֻ��ѡ���ұ߻���ߵ�ǽ��Ȼ���������
��Ȼ�����ܱ�֤���ֲ��ԣ�����ң�����ã���������ȡ��·������������Ч�ġ�����Ҳ�������ڳ��ڲ��ڱ�Ե���Թ�;��Щ�����в���ʾ��Щ���͵��Թ���

��Ϊ������������Թ������׵ص����ˣ���ϣ��ӵ��һ�����������
�ó������ȷ������·���Լ����·�����Ա��������ҳ����ֲ������п��ܻ��������ߡ�

*
���˼·��
��1����ȡ����ĳ��Ϳ���map����洢��ͼ 
��2��wall������ʾ����ߺ��ұ��ߵ��ߵĳ��ȣ���one��handΪ1ʱ��ʾ�ұߣ�Ϊ-1ʱ��ʾ��� ������bfs������̾��� 
��3��getdir�������ڻ�ȡ��ʼλ�� ������ֵ0��1��2��3��ʾ�����ߵ���ʼλ�ã�����ȷ������������ 
��4��wall������ ֻҪ��ǰ���겻Ϊ���ھͻ�һֱ�ƶ���ͨ������dir��ֵ��ȷ���ƶ��ķ����Լ������ƶ����λ�� 
��5��bfs���������ö���ʵ�ֹ������ 
	   
*
�ύ״̬��AC
*
AC�����
220K	16MS
*
���������
5��6��
��������
�������Ա�ʾ ���Թ�����ڲ�ͬ�����ҷ���ͬ�� 


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
