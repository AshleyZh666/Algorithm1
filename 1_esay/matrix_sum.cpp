///n行m列的矩阵
//q行4列的查询
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;
int a[N][N];
int sum[N][N];

// int matrix_sum(int sum[][],int x1,int y1,int x2,int y2){
//     return sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1] ;
// }
// 3 5 4
// 1 7 2 4 5
// 3 6 2 8 4
// 2 1 2 3 3
// 1 1 2 2
// 2 1 3 4
// 1 3 3 4
// 0 1 3 4

// 17
// 27
// 21

int main(){
    // printf("%d\n",q[0][0]);
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
            printf("%d ",sum[i][j]);
         }
         printf("\n");
    }
    while(q--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        // int res = matrix_sum(sum,x1,y1,x2,y2);
        // cout<<res<<endl;
        // sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1] ;
        //////注意x1和y1，即左上的边界应该是的开区间
        cout<<sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]<<endl;
    }
    printf("C 艹 mother fucker\n");
    system("pause");
}