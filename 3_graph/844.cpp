////////�������BFS������n��������ȫ����Ϊ����
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

typedef pair<int , int> PAI;//////��(x,y)��¼����,���д���
const int N = 110;
int n , m ;///�Թ����к���
int d[N][N];//distance
int map[N][N];
queue<PAI> q;
// PAI yd[4] = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
int yd[4][2] = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

int bfs(){
    // int hh = 0 , tt = 0;
    memset(d , -1 , sizeof d);
    ///��ʼ������
    // q[0] = {0 , 0};
    q.push({0,0});
    d[0][0] = 0;///////����00��
    while(!q.empty()){
        //ȡ����ͷ
        // auto t = q[hh++];
        auto t = q.front();
        q.pop();
        //�������������ĸ�����
        for(int i = 0 ; i < 4 ; ++i){
            //////ȡ����Ԫ��
            int x = t.first + yd[i][0];
            int y = t.second + yd[i][1];
            if(x >= 0 && x < n && y >= 0 && y < m && !map[x][y] && d[x][y] == -1){
                d[x][y] = d[t.first][t.second] + 1;////����һ��������x,y
                // q[++tt] = {x,y};//////���
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
    printf("C ܳ mother fucker\n");
    system("pause");
}