#include<iostream>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;

////堆优化迪杰斯特拉的模板，算法复杂度为O( n * n),即只与点的多少有关
//// 所以
//<dist , i: n>
// typedef pair<int , int> PAI;
const int N = 510;
int n , m;
int e[N] , ne[N] , h[N] , w[N], idx;///存的是i到j的距离
int dist[N];///存的是1到i的最短距离，尽量最终
/////////点1开始
bool st[N];/////////有点搞不懂这个s集合

void add(int a, int b , int c){
    e[idx] = b ;///头插b
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int spfa(){
    memset(dist , 0x3f , sizeof(dist));
    dist[1] = 0;
    queue<int> q;
    q.push(1);///点数
    st[1] = true;

    while(q.size()){///结点
        int t = q.front();
        q.pop();
        st[t] = false;

        for(int i = h[t] ; i != -1 ; i = ne[i]){///边
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return  (dist[n] == 0x3f3f3f3f) ? -1:dist[n];
}
// 3 3
// 1 2 2
// 2 3 1
// 1 3 4

//////////////successful

int main(){
    scanf("%d%d" , &n , &m);
    // memset(g , 0x3f , sizeof(g));
    memset(h , -1 , sizeof(h));
    for(int i = 1 ; i <= m ; i++){
        int a, b , c;
        scanf("%d%d%d" , &a,&b,&c);
        // g[a][b] = min(g[a][b] , c);///防止重边
        add(a,b,c);
    }
    cout<<spfa()<<endl;
    printf("C 艹 mother fucker\n");
    system("pause");
}