#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;//////////为什么   要将 N = 20
int n;
char g[N][N];
bool col[N] , gd[N] , ugd[N]; /////////

void dfs(int u){///////// u表示的是到了第u行
    if(u == n){
        for (int i = 0; i < n; i ++ ){
            puts(g[i]);
        }
        puts("");
        return;
    }//////已经确定了u行个皇后
    for (int i = 0; i < n; i ++ ){///其实是代表g[u][i] = 'Q'
        if(!col[i] && !gd[u + i] && !ugd[n - u +i]){
            g[u][i] = 'Q';
            col[i] = gd[u + i] = ugd[n - u +i] = true;
            dfs(u + 1);
            col[i] = gd[u + i] = ugd[n - u +i] = false;
            g[u][i] = '*';////这里要恢复吗？,建议恢复一下
        }
    } 
}

 int main(){
     scanf("%d" , &n);
     for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            g[i][j] = '*';
    dfs(0);
    printf("C 艹 mother fucker\n");
    system("pause");
 }