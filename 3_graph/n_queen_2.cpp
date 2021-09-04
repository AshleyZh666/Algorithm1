#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//暴力搜

const int N = 10;//////////为什么   要将 N = 20
int n;
char g[N][N];
bool row[N],col[N] , gd[N] , ugd[N]; /////////

void dfs(int x, int y , int s){///////// u表示的是到了第u行
    //////列越界
    if (y == n) ++x , y = 0;
    if(x == n){//////说明 x 和 y都溢出
        if (s == n){//////已经确定了u行个皇后
            for (int i = 0; i < n; i ++ ) puts(g[i]);
            puts("");////结果换行  
        }
    }
    else
    {   //////// x < n
        dfs(x , y + 1 , s);//不放，即仍然s
        ////////放皇后即,g[x][y] = 'Q
        if(!row[x]&&!col[y] && !gd[x + y] && !ugd[n - x + y]){
            g[x][y] = 'Q';
            row[x] = col[y] = gd[x + y] = ugd[n - x + y] = true;
            dfs(x , y , s + 1);
            row[x] = col[y] = gd[x + y] = ugd[n - x + y] = false;
            g[x][y] = '*';////这里要恢复吗？,建议恢复一下
        }
    }
    
}

 int main(){
     scanf("%d" , &n);
     for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            g[i][j] = '*';
    dfs(0 , 0 , 0);
    printf("C 艹 mother fucker\n");
    system("pause");
 }