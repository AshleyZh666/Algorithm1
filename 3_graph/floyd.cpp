#include<iostream>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1010;
const int INF = 1e9;

int d[N][N];   //d[a][b]表示a到b的最短距离
int n , m;

void print_d(){
    cout<<"d =  "<<endl;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
}
void init_floyd(){
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= n ; ++j)
            d[i][j] = (i == j) ? 0 : INF;
    print_d();
}
int floyd(){
    for(int k = 1 ; k <= n ; ++k)
        for(int i = 1 ; i <= n ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                d[i][j] = min(d[i][j] , d[i][k] +d[k][j]);
    return d[1][n];
}
// 3 3
// 1 2 2
// 2 3 1
// 1 3 4
int main(){
    // cout<<"sizeof = "<<sizeof(d)<<endl;
    // memset(d , 0x3f , sizeof(d));
    // cout<<INF<<endl;

            // if (i == j)
            //     d[i][j] = 0;
            // else 
            //     d[i][j] = INF;
    scanf("%d%d" , &n , &m);
    init_floyd();
    for(int i = 1 ; i <= m ; i++){
        int a , b , c;
        scanf("%d%d%d" , &a,&b,&c);
        d[a][b] = min(d[a][b] , c);///防止重边
    }
    cout<<floyd()<<endl;

    printf("\nC 艹 mother fucker\n");
    system("pause");
}
