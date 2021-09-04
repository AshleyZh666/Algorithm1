#include<istream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 100010  , M = N * 2; 
int n , m;
int h[N] , e[M] , ne[M] , idx;////链表
bool st[N] ;////即表示i号结点是否搜索过

void add(int a , int b){
    e[idx] = b ;
    ne[idx] = h[a] ;//////h[a]即头节点
    h[a] = idx++ ;
}

void dfs(int u){
    st[u] = true;///标记一下，搜索了u号点
    //遍历其所有的出边
    for(int i = h[u] ; i != -1 ; i = ne[i]){
        int j = e[i];
        if (! st[j])/////////真的不是 st[i]
            dfs(j);////////真的不是dfs(i)吗
    }
}

int main(){
    memset(h , -1 , sizeof h);
    dfs(1);
    printf("C 艹 mother fucker\n");
    system("pause");
}
