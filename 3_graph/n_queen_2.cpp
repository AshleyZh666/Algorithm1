#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//������

const int N = 10;//////////Ϊʲô   Ҫ�� N = 20
int n;
char g[N][N];
bool row[N],col[N] , gd[N] , ugd[N]; /////////

void dfs(int x, int y , int s){///////// u��ʾ���ǵ��˵�u��
    //////��Խ��
    if (y == n) ++x , y = 0;
    if(x == n){//////˵�� x �� y�����
        if (s == n){//////�Ѿ�ȷ����u�и��ʺ�
            for (int i = 0; i < n; i ++ ) puts(g[i]);
            puts("");////�������  
        }
    }
    else
    {   //////// x < n
        dfs(x , y + 1 , s);//���ţ�����Ȼs
        ////////�Żʺ�,g[x][y] = 'Q
        if(!row[x]&&!col[y] && !gd[x + y] && !ugd[n - x + y]){
            g[x][y] = 'Q';
            row[x] = col[y] = gd[x + y] = ugd[n - x + y] = true;
            dfs(x , y , s + 1);
            row[x] = col[y] = gd[x + y] = ugd[n - x + y] = false;
            g[x][y] = '*';////����Ҫ�ָ���,����ָ�һ��
        }
    }
    
}

 int main(){
     scanf("%d" , &n);
     for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            g[i][j] = '*';
    dfs(0 , 0 , 0);
    printf("C ܳ mother fucker\n");
    system("pause");
 }