#include<iostream>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;

////���Ż��Ͻ�˹������ģ�壬�㷨���Ӷ�ΪO( n * n),��ֻ���Ķ����й�
//// ����
//<dist , i: n>
// typedef pair<int , int> PAI;
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

int spfa(){
    memset(dist , 0x3f , sizeof(dist));
    dist[1] = 0;
    queue<int> q;
    q.push(1);///����
    st[1] = true;

    while(q.size()){///���
        int t = q.front();
        q.pop();
        st[t] = false;

        for(int i = h[t] ; i != -1 ; i = ne[i]){///��
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
        // g[a][b] = min(g[a][b] , c);///��ֹ�ر�
        add(a,b,c);
    }
    cout<<spfa()<<endl;
    printf("C ܳ mother fucker\n");
    system("pause");
}