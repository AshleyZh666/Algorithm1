////////  n-皇后问题，即在n * n的国际象棋的棋盘上，放置n个皇后
/////// 使其不能在棋盘内，互相攻击，皇后能够横，竖，斜
/////// 剪纸即提前判断，当前的情况不合法，不再向更深方向搜索
/////// 有回溯，有剪枝
////////剪枝常见有最优剪枝和可行性剪枝，即不符合最优和可行性就会被剪枝

#include<iostream>
#include<string.h>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 10;
int n ;
char q[N][N];///// 
//同样的还有 bool 判断，即那些情况是合法的
//dg为主对角线是否合法，udg则为副对角线是否合法

///如何理解呢，如,   g[i][j] = 'Q'
//则 col[j] = true ,
bool col[N] , dg[N] , udg[N];/////默认都是0，即false


void dfs(int u ){
    if(u == n){//到达了根节点，则输出结果
        for(int i = 0 ; i < n ; ++i) {
            puts(q[i]);
        }
        puts("");
        return;
    }
    for(int i = 0 ; i < n ; ++i){
        if(!col[i] && !dg[u + i] && !udg[i - u + n])
            q[u][i] = 'Q';
            col[i] = dg[u + i] = udg[i - u + n] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[i - u + n] = false;
            q[u][i] = '*';
    }
}

int main(){
    // int n ;
    // cin>> n ;
    scanf("%d" , &n);
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ;++j)
            q[i][j] = '*';
    dfs(0);/////即遍历第 0 层 

    printf("C 艹 mother fucker\n");
    system("pause");
}