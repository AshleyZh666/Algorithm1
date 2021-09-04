///输出 1 到 n点的最短距离，不行就输出 -1
///其中m行2列表示是从a到b结点存在边,a到b。
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string.h>

using namespace std;

const int N = 100010;

int n , m ;
int h[N] , e[N] , ne[N] , idx;
int q[N] ,  d[N];

void add(int a, int b){//h[a]的链表后插入结点
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int bfs(){
    int hh = 0, tt = 0;//////为什么初始状态下，tt = 0,
    /////因为一会队内初始化，入队有一个成员
    q[0] = 1;///栈中,1号点？？？
    memset(d , -1 , sizeof(d));//////// -1 表示的是此结点没有访问
    // d[1] = 0;//////
    d[1] = 0;
    while(hh <= tt){
        //获取队首元素
        int t  = q[hh++];
        for(int i = h[t] ; i != -1 ;i = ne[i]){
            int j = e[i];///i号结点
            // cout<<t<<"的后继结点为"<<j<<endl;
            if (d[j] == -1)  
            {   
                d[j] = d[t] + 1 ;
                q[++tt] = j;
            }
        }
    }
    // for(int i = 0 ; i < n ; i ++) printf("%d" , d[i]);
    return d[n];
}

// 4 5
// 1 2
// 2 3
// 3 4
// 1 3
// 1 4

 int main(){
     scanf("%d%d" , &n , &m );
     memset(h , -1 ,sizeof(h));
     for(int i = 0 ; i < m ; ++i){
         int a,b;
         scanf("%d%d",&a , &b);
         add(a,b);
    }
    printf("%d" , bfs());
    printf("\nC 艹 mother fucker\n");
    system("pause");
 }
