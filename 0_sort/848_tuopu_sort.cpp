///////有向无环图
///// 848 、有向图的拓扑序列
//input: n结点 m 边
// 3 3
// 1 2
// 2 3
// 1 3
//Ouput:
//1 2 3

#include<iostream>
#include<cstring>
#include<algorithm>
#include<string.h>

using namespace std;

const int N = 1000010;
int n , m;
int idx , e[N] , ne[N] , h[N];
int q[N] , d[N] ;////////d[N] 存点i的入度？？？

void add(int a, int b){
    ///////头插法
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
//////肯定需要返回能否拓扑排序
bool tuopu_sort(){
    int hh = 0 , tt = -1;
    // q[++tt] = ;/////找到第一个入度为 0 的结点
    for(int i = 1 ; i <= n ; ++i) ///////结点从1开始
        if(!d[i]) 
            q[++tt] = i;
    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t] ; i != -1 ; i = ne[i]){
            int j = e[i];
            d[j]--;///想到与去掉 结点t
            if(!d[j]) q[++tt] = j;
        }
    }
    // 如果所有点都入队了，说明存在拓扑序列；否则不存在拓扑序列。
    // cout<<"hh = "<<hh<<" tt = "<<tt<<endl;
    return tt == n - 1;///////还真就是进入队列有n个点，只看 tt
}
bool topsort()
{
    int hh = 0, tt = -1;

    // d[i] 存储点i的入度
    for (int i = 1; i <= n; i ++ )
        if (!d[i])
            q[ ++ tt] = i;

    while (hh <= tt)
    {
        int t = q[hh ++ ];

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (-- d[j] == 0)
                q[ ++ tt] = j;
        }
    }
    // cout<<"hh = "<<hh<<" tt = "<<tt<<endl;
    // 如果所有点都入队了，说明存在拓扑序列；否则不存在拓扑序列。
    return tt == n - 1;
}



int main(){
    ////////一定要注意 ，n m是否全局变量
    scanf("%d%d" , &n , &m);
    // memset(d, 0 , sizeof(d));////////默认初始化为 0 
    memset(h , -1 , sizeof(h));
    for(int i = 0 ; i < m ; ++i) {
        int a, b;
        scanf("%d%d" , &a , &b);
        add(a,b);
        d[b]++;
    }
    // cout<<topsort()<<endl;
    if (tuopu_sort()){
        for(int i = 0 ; i < n ;++i) printf("%d " , q[i]);
        puts("");
    }
    else{
        puts("-1");
    }
    printf("\nC 艹 mother fucker\n");
    system("pause");
}