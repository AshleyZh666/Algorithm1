#include<iostream>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;

////���Ż��Ͻ�˹������ģ�壬�㷨���Ӷ�ΪO( n * n),��ֻ���Ķ����й�
//// ����
//<dist , i: n>
typedef pair<int , int> PAI;
const int N = 510;
int n , m;
int e[N] , ne[N] , h[N] , w[N], idx;///�����i��j�ľ���
int dist[N];///�����1��i����̾��룬��������
/////////��1��ʼ
bool st[N];/////////�е�㲻�����s����

void add(int a, int b , int c){
    e[idx] = b ;///ͷ��b
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dijkstra(){
    memset(dist , 0x3f , sizeof(dist));
    dist[1] = 0;

    priority_queue<PAI , vector<PAI> , greater<PAI>> heap;
    heap.push({0 , 1});
    ///////��δȷ����̵ĵ���ҵ�ȷ�������·��
    while(!heap.empty()){
        auto t = heap.top();
        heap.pop();
        int distance = t.first , vec = t.second;
        ///////��������t 
        ///////////////˼�������st[vec]
        if(st[vec]) continue;//�Ƿ����,���·���if(!st[vec])��
        // if(!st[vec])
            for(int i = h[vec] ; i != -1 ; i = ne[i]){
                int j = e[i];//////////////�ص����w[i]
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
    // ///////����������ľ���
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
        // g[a][b] = min(g[a][b] , c);///��ֹ�ر�
        add(a,b,c);
    }
    cout<<dijkstra()<<endl;
    printf("C ܳ mother fucker\n");
    system("pause");
}