#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;
int a[N][N] , b[N][N];
//q行的5列的
void matrix_diff(int x1 , int y1 , int x2 , int y2 , int c){
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
// 3 5 1
// 1 7 2 4 5
// 3 6 2 8 4
// 2 1 2 3 3
// 1 1 2 2 4
void print_arr(int x[N][N] , int n , int m){
    for(int i = 0 ; i <= n ; ++i){
        for(int j = 0 ; j <= m ; ++j){
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n , m ,q;
    scanf("%d%d%d" , &n , &m , &q);
    for(int i = 1; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            int c;
            scanf("%d",&c);
            matrix_diff(i,j,i,j,c);
        }
    }
    print_arr(b,n,m);
    while(q--){
            int x1,y1,x2,y2,c;
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
            matrix_diff(x1,y1,x2,y2,c);
    }
    print_arr(b,n,m);
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + b[i][j];
            // cout<<a[i][j]<<" ";
            // printf("%d ",a[i][j]);
        }
        // cout<<endl;
        // printf("\n");
    }
    cout<<endl;
    print_arr(a,n,m);
    system("pause");
}
