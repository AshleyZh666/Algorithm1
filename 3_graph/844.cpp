////////最基础的BFS程序，以n个数数字全排列为例；
///////
///////
///////

#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstring>
#include<queue>

// 5 5
// 0 1 0 0 0
// 0 1 0 1 0
// 0 0 0 0 0
// 0 1 1 1 0
// 0 0 0 1 0

using namespace std;

typedef pair<int , int> PAI;//////即(x,y)记录坐标,队列存入
const int N = 110;
int n , m ;///迷宫的行和列
int d[N][N];//distance
int map[N][N];
queue<PAI> q;
// PAI yd[4] = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
int yd[4][2] = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

int bfs(){
    // int hh = 0 , tt = 0;
    memset(d , -1 , sizeof d);
    ///初始化队列
    // q[0] = {0 , 0};
    q.push({0,0});
    d[0][0] = 0;///////走了00点
    while(!q.empty()){
        //取出队头
        // auto t = q[hh++];
        auto t = q.front();
        q.pop();
        //定义上下左右四个方向
        for(int i = 0 ; i < 4 ; ++i){
            //////取队首元素
            int x = t.first + yd[i][0];
            int y = t.second + yd[i][1];
            if(x >= 0 && x < n && y >= 0 && y < m && !map[x][y] && d[x][y] == -1){
                d[x][y] = d[t.first][t.second] + 1;////走了一步，到了x,y
                // q[++tt] = {x,y};//////入队
                q.push({x,y});
            }
        }
    }
    return d[n - 1][m -1];
}


int main(){
    scanf("%d%d" , &n , &m);
    for(int i = 0 ; i < n ;++i)
        for(int j = 0 ; j < m ; ++j)
            scanf("%d" , &map[i][j]);
    printf("%d\n" ,bfs());
    printf("C 艹 mother fucker\n");
    system("pause");
}