#include<iostream>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;

////bellman的模板，算法复杂度为O( n * m)
////  最大得优势是限制k边数得最短路径

const int N = 510 , M = 10010;
int n , m , k;///////k是什莫意思呢////限制k个结点
// int e[N] , ne[N] , h[N] , w[N], idx;///存的是i到j的距离
////////存储方式是struct
int dist[N] , backup[N];///backup是什么作用呢

struct Edge
{
    /* data */
    int a,b,w;
}edge[M];


int bellman_ford(){
    // cout<<"k = "<<k<<endl;
    memset(dist , 0x3f , sizeof(dist));
    dist[1] = 0;
    for(int i = 0 ; i < k ;++i){///最多处理到第i条边
        memcpy(backup , dist , sizeof(dist));//////缓冲,记住上一次循环得结果,
        for(int j = 0 ; j < m ; ++j){//边
            int a = edge[j].a , b = edge[j].b , w = edge[j].w;
            dist[b] = min(dist[b] , backup[a] + w);
        }
    }
    // cout<<dist[1]<<" ** "<<dist[2]<<endl;
    // if (dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}

// 3 3 1
// 1 2 1
// 2 3 1
// 1 3 3

//////////////successful

int main(){
    // cout<<0x3f<<endl;
    scanf("%d%d%d" , &n , &m , &k);
    // memset(g , 0x3f , sizeof(g));
    // memset(h , -1 , sizeof(h));
    for(int i = 0 ; i < m ; ++i){
        int a, b , w;
        scanf("%d%d%d" , &a,&b,&w);
        // g[a][b] = min(g[a][b] , c);///防止重边
        // edge[i].a = a;
        // edge[i].b = b;
        // edge[i].w = w;
        edge[i] = {a,b,w};
    }
    int t = bellman_ford();
    ////注意此处得判断
    if (t > 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d\n" , t);
    // printf("C 艹 mother fucker\n");
    // system("pause");
}