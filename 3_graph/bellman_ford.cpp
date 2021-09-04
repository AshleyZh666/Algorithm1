#include<iostream>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;

////bellman��ģ�壬�㷨���Ӷ�ΪO( n * m)
////  ��������������k���������·��

const int N = 510 , M = 10010;
int n , m , k;///////k��ʲĪ��˼��////����k�����
// int e[N] , ne[N] , h[N] , w[N], idx;///�����i��j�ľ���
////////�洢��ʽ��struct
int dist[N] , backup[N];///backup��ʲô������

struct Edge
{
    /* data */
    int a,b,w;
}edge[M];


int bellman_ford(){
    // cout<<"k = "<<k<<endl;
    memset(dist , 0x3f , sizeof(dist));
    dist[1] = 0;
    for(int i = 0 ; i < k ;++i){///��ദ����i����
        memcpy(backup , dist , sizeof(dist));//////����,��ס��һ��ѭ���ý��,
        for(int j = 0 ; j < m ; ++j){//��
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
        // g[a][b] = min(g[a][b] , c);///��ֹ�ر�
        // edge[i].a = a;
        // edge[i].b = b;
        // edge[i].w = w;
        edge[i] = {a,b,w};
    }
    int t = bellman_ford();
    ////ע��˴����ж�
    if (t > 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d\n" , t);
    // printf("C ܳ mother fucker\n");
    // system("pause");
}