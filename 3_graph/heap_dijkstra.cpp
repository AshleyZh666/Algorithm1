#include<iostream>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;

////堆优化迪杰斯特拉的模板，算法复杂度为O( n * n),即只与点的多少有关
//// 所以
//<dist , i: n>
typedef pair<int , int> PAI;
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

int dijkstra(){
    memset(dist , 0x3f , sizeof(dist));
    dist[1] = 0;

    priority_queue<PAI , vector<PAI> , greater<PAI>> heap;
    heap.push({0 , 1});
    ///////从未确定最短的点里，找到确定的最短路径
    while(!heap.empty()){
        auto t = heap.top();
        heap.pop();
        int distance = t.first , vec = t.second;
        ///////即必须是t 
        ///////////////思考这里的st[vec]
        if(st[vec]) continue;//是否可以,以下放在if(!st[vec])中
        // if(!st[vec])
            for(int i = h[vec] ; i != -1 ; i = ne[i]){
                int j = e[i];//////////////重点理解w[i]
                if(dist[j] > distance + w[i]) {
                    dist[j] = distance + w[i];
                    heap.push({dist[j] , j});
                }
            }
        
    }


    // for(int i = 0 ; i < n ; ++i){
    //     // int t = 1;//////
    //     int t = -1;
    //     for(int j = 1 ; j <= n ; ++j){
    //         // if(!st[j] && dist[t] > dist[j])
    //         if(!st[j] && (t == -1 ||dist[t] > dist[j]))
    //             t = j;
    //     }
    //     st[t] = true;
    // ///////更新其他点的距离
    //     for(int j = 1 ; j < n ; ++j)
    //         dist[j] = min(dist[j] , dist[t] + g[t][j]);
    // } 
    ///////
    // if (dist[n] == 0x3f3f3f3f) return -1;
    // return dist[n];
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
    cout<<dijkstra()<<endl;
    printf("C 艹 mother fucker\n");
    system("pause");
}