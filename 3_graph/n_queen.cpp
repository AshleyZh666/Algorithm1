#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;//////////Ϊʲô   Ҫ�� N = 20
int n;
char g[N][N];
bool col[N] , gd[N] , ugd[N]; /////////

void dfs(int u){///////// u��ʾ���ǵ��˵�u��
    if(u == n){
        for (int i = 0; i < n; i ++ ){
            puts(g[i]);
        }
        puts("");
        return;
    }//////�Ѿ�ȷ����u�и��ʺ�
    for (int i = 0; i < n; i ++ ){///��ʵ�Ǵ���g[u][i] = 'Q'
        if(!col[i] && !gd[u + i] && !ugd[n - u +i]){
            g[u][i] = 'Q';
            col[i] = gd[u + i] = ugd[n - u +i] = true;
            dfs(u + 1);
            col[i] = gd[u + i] = ugd[n - u +i] = false;
            g[u][i] = '*';////����Ҫ�ָ���,����ָ�һ��
        }
    } 
}

 int main(){
     scanf("%d" , &n);
     for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            g[i][j] = '*';
    dfs(0);
    printf("C ܳ mother fucker\n");
    system("pause");
 }