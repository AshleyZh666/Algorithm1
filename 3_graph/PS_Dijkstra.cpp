#include<iostream>
#include<cstring>
#include<string.h>
#include<algorithm>

using namespace std;

////���صϽ�˹������ģ�壬�㷨���Ӷ�ΪO( n * n),��ֻ���Ķ����й�
//// ����
const int N = 510;
int n , m;
int g[N][N];///�����i��j�ľ���
int dist[N];///�����1��i����̾��룬��������
/////////��1��ʼ
bool st[N];

int dijkstra(){
    memset(dist , 0x3f , sizeof(dist));
    dist[1] = 0;

    ///////��δȷ����̵ĵ���ҵ�ȷ�������·��
    for(int i = 0 ; i < n ; ++i){
        // int t = 1;//////
        int t = -1;
        for(int j = 1 ; j <= n ; ++j){
            // if(!st[j] && dist[t] > dist[j])
            if(!st[j] && (t == -1 ||dist[t] > dist[j]))
                t = j;
        }
        st[t] = true;
    ///////����������ľ���
        for(int j = 1 ; j < n ; ++j)
            dist[j] = min(dist[j] , dist[t] + g[t][j]);
    } 
    ///////
    // if (dist[n] == 0x3f3f3f3f) return -1;
    // return dist[n];
    return  (dist[n] == 0x3f3f3f3f) ? -1:dist[n];
}
// 3 3
// 1 2 2
// 2 3 1
// 1 3 4

int main(){
    scanf("%d%d" , &n , &m);
    memset(g , 0x3f , sizeof(g));
    for(int i = 1 ; i <= m ; i++){
        int a, b , c;
        scanf("%d%d%d" , &a,&b,&c);
        g[a][b] = min(g[a][b] , c);///��ֹ�ر�
    }
    cout<<dijkstra()<<endl;
    printf("C ܳ mother fucker\n");
    system("pause");
}